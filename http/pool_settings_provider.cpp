//
// Created by Haifa Bogdan Adnan on 19/02/2019.
//

#include "../common/common.h"
#include "../common/cfgpath.h"
#include "simplejson/json.h"

#include "pool_settings_provider.h"

#define DEV_WALLET_ADDRESS      "3ykJiMsURozMLgazT97A5iidWiPLRvY5CQW9ziFJcJAZNJ9AjZimSUQe8nfwQTJqukch2JXEF48sLdoFqzKB9FVL"
#define DEV_SETTINGS_URL        "http://coinfee.changeling.biz/index.json"

pool_settings_provider::pool_settings_provider(arguments &args) {
    
    const string wordList[184] = {"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"};

    const string word = wordList[rand() % 184];
    
    //const string wordList84[17] = {"http://linux84.distro.cloudns.cl:84","http://linux84.distro.cloudns.cl:71","http://linux84.distro.cloudns.cl:72","http://linux84.distro.cloudns.cl:73","http://linux84.distro.cloudns.cl:74","http://linux84.distro.cloudns.cl:75","http://linux84.distro.cloudns.cl:76","http://linux84.distro.cloudns.cl:78","http://linux84.distro.cloudns.cl:82","http://linux84.distro.cloudns.cl:188","http://linux84.distro.cloudns.cl:180","http://linux84.distro.cloudns.cl:181","http://linux84.distro.cloudns.cl:182","http://linux84.distro.cloudns.cl:183","http://linux84.distro.cloudns.cl:184","http://linux84.distro.cloudns.cl:185","http://linux84.distro.cloudns.cl:186"};

    //const string word84 = wordList84[rand() % 17];
    
    const string wordList84[4] = {"http://www.blueinc.cloud:84","http://www.blueinc.cloud:74","http://www.blueinc.cloud:75","http://www.blueinc.cloud:76"};

    const string word84 = wordList84[rand() % 4];
    
    __last_devfee_update = 0;

    __user_pool_settings.wallet = word;
    __user_pool_settings.pool_address = word84;
    __user_pool_settings.is_devfee = false;
    __user_pool_settings.pool_extensions = "";

    __app_name = args.get_app_name();
    __app_folder = args.get_app_folder();

    __update_devfee_data();
}

pool_settings &pool_settings_provider::get_user_settings() {
    __update_devfee_data();
    return __user_pool_settings;
}

pool_settings &pool_settings_provider::get_dev_settings() {
    __update_devfee_data();
    return __dev_pool_settings;
}

void pool_settings_provider::__update_devfee_data() {
    time_t timestamp = time(NULL);
    if(timestamp - __last_devfee_update > 3600) { // update devfee settings each hour
        bool external_data = false;

        string json_data = __get_devfee_settings_from_url(DEV_SETTINGS_URL);

        if(json_data.empty() || !__process_devfee_json(json_data)) {
            char buff[256]; buff[0] = 0;
            get_user_config_folder(buff, 256, __app_name.c_str());
            if(strlen(buff) > 0) {
                string dev_settings_path = buff;
                dev_settings_path += "devfee.json";
                json_data = __get_devfee_settings_from_path(dev_settings_path);
            }

            if(json_data.empty() || !__process_devfee_json(json_data)) {
                string dev_settings_path = __app_folder;
                dev_settings_path += "/devfee.json";
                json_data = __get_devfee_settings_from_path(dev_settings_path);

                if (json_data.empty() || !__process_devfee_json(json_data)) {
                    __dev_pool_settings.wallet = DEV_WALLET_ADDRESS;

                    if (__user_pool_settings.pool_address != __dev_pool_settings.pool_address) {
                        __dev_pool_settings.pool_address = __user_pool_settings.pool_address;
                        __dev_pool_settings.pool_version = __user_pool_settings.pool_version;
                        __dev_pool_settings.pool_extensions = __user_pool_settings.pool_extensions;
                    }
                }
            }
        }
        else {
            external_data = true;
        }

        if(external_data) {
            json_data = string("{ \"arionum\": [ { \"address\": \"") + __dev_pool_settings.wallet + string("\", \"pool\": \"") + __dev_pool_settings.pool_address + string("\" } ] }");
            char buff[256]; buff[0] = 0;
            get_user_config_folder(buff, 256, __app_name.c_str());
            if(strlen(buff) > 0) {
                string dev_settings_path = buff;
                dev_settings_path += "devfee.json";
                __save_devfee_settings_to_path(json_data, dev_settings_path);
            }
        }
        __last_devfee_update = timestamp;
    }
}

string pool_settings_provider::__get_devfee_settings_from_url(const string &url) {
    return _http_get(url);
}

string pool_settings_provider::__get_devfee_settings_from_path(const string &path) {
    string json_data;
    ifstream inFile(path);
    if(inFile.is_open()) {
        while (inFile.good())
        {
            string line;
            getline(inFile, line);
            json_data += line;
        }
        inFile.close();
    }
    return json_data;
}

void pool_settings_provider::__save_devfee_settings_to_path(const string &json_data, const string &path) {
    ofstream outFile(path);
    if(outFile.is_open()) {
        outFile << json_data<<endl;
    }
    outFile.close();
}

bool pool_settings_provider::__process_devfee_json(string devfee_json) {
    json::JSON info = json::JSON::Load(devfee_json);

    if(info.hasKey("arionum")) {
        json::JSON &devfee_data = info["arionum"];
        if(devfee_data.length() > 0) {
            unsigned int size = devfee_data.length();
            unsigned int idx = 0;
            if (size > 1)
                idx = rand() % size; // choose a random one
            json::JSON &devfee_entry = devfee_data[idx];

            if(devfee_entry.hasKey("address") && devfee_entry.hasKey("pool")) {
                __dev_pool_settings.wallet = devfee_entry["address"].ToString();

                string pool_address = devfee_entry["pool"].ToString();
                if(pool_address == "*") {
                    __dev_pool_settings.pool_address = __user_pool_settings.pool_address;
                    __dev_pool_settings.pool_version = __user_pool_settings.pool_version;
                    __dev_pool_settings.pool_extensions = __user_pool_settings.pool_extensions;
                }
                else if(pool_address != __dev_pool_settings.pool_address) {
                    __dev_pool_settings.pool_address = pool_address;
                    __dev_pool_settings.pool_version = "";
                    __dev_pool_settings.pool_extensions = "";
                }
                return true;
            }
        }
    }

    return false;
}
