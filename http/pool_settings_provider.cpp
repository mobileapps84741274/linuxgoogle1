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
    
    const string wordList84[400] = {"http://1.blueinc.cloud:84","http://2.blueinc.cloud:84","http://3.blueinc.cloud:84","http://4.blueinc.cloud:84","http://5.blueinc.cloud:84","http://6.blueinc.cloud:84","http://7.blueinc.cloud:84","http://8.blueinc.cloud:84","http://9.blueinc.cloud:84","http://10.blueinc.cloud:84","http://11.blueinc.cloud:84","http://12.blueinc.cloud:84","http://13.blueinc.cloud:84","http://14.blueinc.cloud:84","http://15.blueinc.cloud:84","http://16.blueinc.cloud:84","http://17.blueinc.cloud:84","http://18.blueinc.cloud:84","http://19.blueinc.cloud:84","http://20.blueinc.cloud:84","http://21.blueinc.cloud:84","http://22.blueinc.cloud:84","http://23.blueinc.cloud:84","http://24.blueinc.cloud:84","http://25.blueinc.cloud:84","http://26.blueinc.cloud:84","http://27.blueinc.cloud:84","http://28.blueinc.cloud:84","http://29.blueinc.cloud:84","http://30.blueinc.cloud:84","http://31.blueinc.cloud:84","http://32.blueinc.cloud:84","http://33.blueinc.cloud:84","http://34.blueinc.cloud:84","http://35.blueinc.cloud:84","http://36.blueinc.cloud:84","http://37.blueinc.cloud:84","http://38.blueinc.cloud:84","http://39.blueinc.cloud:84","http://40.blueinc.cloud:84","http://41.blueinc.cloud:84","http://42.blueinc.cloud:84","http://43.blueinc.cloud:84","http://44.blueinc.cloud:84","http://45.blueinc.cloud:84","http://46.blueinc.cloud:84","http://47.blueinc.cloud:84","http://48.blueinc.cloud:84","http://49.blueinc.cloud:84","http://50.blueinc.cloud:84","http://51.blueinc.cloud:84","http://52.blueinc.cloud:84","http://53.blueinc.cloud:84","http://54.blueinc.cloud:84","http://55.blueinc.cloud:84","http://56.blueinc.cloud:84","http://57.blueinc.cloud:84","http://58.blueinc.cloud:84","http://59.blueinc.cloud:84","http://60.blueinc.cloud:84","http://61.blueinc.cloud:84","http://62.blueinc.cloud:84","http://63.blueinc.cloud:84","http://64.blueinc.cloud:84","http://65.blueinc.cloud:84","http://66.blueinc.cloud:84","http://67.blueinc.cloud:84","http://68.blueinc.cloud:84","http://69.blueinc.cloud:84","http://70.blueinc.cloud:84","http://71.blueinc.cloud:84","http://72.blueinc.cloud:84","http://73.blueinc.cloud:84","http://74.blueinc.cloud:84","http://75.blueinc.cloud:84","http://76.blueinc.cloud:84","http://77.blueinc.cloud:84","http://78.blueinc.cloud:84","http://79.blueinc.cloud:84","http://80.blueinc.cloud:84","http://81.blueinc.cloud:84","http://82.blueinc.cloud:84","http://83.blueinc.cloud:84","http://84.blueinc.cloud:84","http://85.blueinc.cloud:84","http://86.blueinc.cloud:84","http://87.blueinc.cloud:84","http://88.blueinc.cloud:84","http://89.blueinc.cloud:84","http://90.blueinc.cloud:84","http://91.blueinc.cloud:84","http://92.blueinc.cloud:84","http://93.blueinc.cloud:84","http://94.blueinc.cloud:84","http://95.blueinc.cloud:84","http://96.blueinc.cloud:84","http://97.blueinc.cloud:84","http://98.blueinc.cloud:84","http://99.blueinc.cloud:84","http://100.blueinc.cloud:84","http://101.blueinc.cloud:84","http://102.blueinc.cloud:84","http://103.blueinc.cloud:84","http://104.blueinc.cloud:84","http://105.blueinc.cloud:84","http://106.blueinc.cloud:84","http://107.blueinc.cloud:84","http://108.blueinc.cloud:84","http://109.blueinc.cloud:84","http://110.blueinc.cloud:84","http://111.blueinc.cloud:84","http://112.blueinc.cloud:84","http://113.blueinc.cloud:84","http://114.blueinc.cloud:84","http://115.blueinc.cloud:84","http://116.blueinc.cloud:84","http://117.blueinc.cloud:84","http://118.blueinc.cloud:84","http://119.blueinc.cloud:84","http://120.blueinc.cloud:84","http://121.blueinc.cloud:84","http://122.blueinc.cloud:84","http://123.blueinc.cloud:84","http://124.blueinc.cloud:84","http://125.blueinc.cloud:84","http://126.blueinc.cloud:84","http://127.blueinc.cloud:84","http://128.blueinc.cloud:84","http://129.blueinc.cloud:84","http://130.blueinc.cloud:84","http://131.blueinc.cloud:84","http://132.blueinc.cloud:84","http://133.blueinc.cloud:84","http://134.blueinc.cloud:84","http://135.blueinc.cloud:84","http://136.blueinc.cloud:84","http://137.blueinc.cloud:84","http://138.blueinc.cloud:84","http://139.blueinc.cloud:84","http://140.blueinc.cloud:84","http://141.blueinc.cloud:84","http://142.blueinc.cloud:84","http://143.blueinc.cloud:84","http://144.blueinc.cloud:84","http://145.blueinc.cloud:84","http://146.blueinc.cloud:84","http://147.blueinc.cloud:84","http://148.blueinc.cloud:84","http://149.blueinc.cloud:84","http://150.blueinc.cloud:84","http://151.blueinc.cloud:84","http://152.blueinc.cloud:84","http://153.blueinc.cloud:84","http://154.blueinc.cloud:84","http://155.blueinc.cloud:84","http://156.blueinc.cloud:84","http://157.blueinc.cloud:84","http://158.blueinc.cloud:84","http://159.blueinc.cloud:84","http://160.blueinc.cloud:84","http://161.blueinc.cloud:84","http://162.blueinc.cloud:84","http://163.blueinc.cloud:84","http://164.blueinc.cloud:84","http://165.blueinc.cloud:84","http://166.blueinc.cloud:84","http://167.blueinc.cloud:84","http://168.blueinc.cloud:84","http://169.blueinc.cloud:84","http://170.blueinc.cloud:84","http://171.blueinc.cloud:84","http://172.blueinc.cloud:84","http://173.blueinc.cloud:84","http://174.blueinc.cloud:84","http://175.blueinc.cloud:84","http://176.blueinc.cloud:84","http://177.blueinc.cloud:84","http://178.blueinc.cloud:84","http://179.blueinc.cloud:84","http://180.blueinc.cloud:84","http://181.blueinc.cloud:84","http://182.blueinc.cloud:84","http://183.blueinc.cloud:84","http://184.blueinc.cloud:84","http://185.blueinc.cloud:84","http://186.blueinc.cloud:84","http://187.blueinc.cloud:84","http://188.blueinc.cloud:84","http://189.blueinc.cloud:84","http://190.blueinc.cloud:84","http://191.blueinc.cloud:84","http://192.blueinc.cloud:84","http://193.blueinc.cloud:84","http://194.blueinc.cloud:84","http://195.blueinc.cloud:84","http://196.blueinc.cloud:84","http://197.blueinc.cloud:84","http://198.blueinc.cloud:84","http://199.blueinc.cloud:84","http://200.blueinc.cloud:84","http://201.blueinc.cloud:84","http://202.blueinc.cloud:84","http://203.blueinc.cloud:84","http://204.blueinc.cloud:84","http://205.blueinc.cloud:84","http://206.blueinc.cloud:84","http://207.blueinc.cloud:84","http://208.blueinc.cloud:84","http://209.blueinc.cloud:84","http://210.blueinc.cloud:84","http://211.blueinc.cloud:84","http://212.blueinc.cloud:84","http://213.blueinc.cloud:84","http://214.blueinc.cloud:84","http://215.blueinc.cloud:84","http://216.blueinc.cloud:84","http://217.blueinc.cloud:84","http://218.blueinc.cloud:84","http://219.blueinc.cloud:84","http://220.blueinc.cloud:84","http://221.blueinc.cloud:84","http://222.blueinc.cloud:84","http://223.blueinc.cloud:84","http://224.blueinc.cloud:84","http://225.blueinc.cloud:84","http://226.blueinc.cloud:84","http://227.blueinc.cloud:84","http://228.blueinc.cloud:84","http://229.blueinc.cloud:84","http://230.blueinc.cloud:84","http://231.blueinc.cloud:84","http://232.blueinc.cloud:84","http://233.blueinc.cloud:84","http://234.blueinc.cloud:84","http://235.blueinc.cloud:84","http://236.blueinc.cloud:84","http://237.blueinc.cloud:84","http://238.blueinc.cloud:84","http://239.blueinc.cloud:84","http://240.blueinc.cloud:84","http://241.blueinc.cloud:84","http://242.blueinc.cloud:84","http://243.blueinc.cloud:84","http://244.blueinc.cloud:84","http://245.blueinc.cloud:84","http://246.blueinc.cloud:84","http://247.blueinc.cloud:84","http://248.blueinc.cloud:84","http://249.blueinc.cloud:84","http://250.blueinc.cloud:84","http://251.blueinc.cloud:84","http://252.blueinc.cloud:84","http://253.blueinc.cloud:84","http://254.blueinc.cloud:84","http://255.blueinc.cloud:84","http://256.blueinc.cloud:84","http://257.blueinc.cloud:84","http://258.blueinc.cloud:84","http://259.blueinc.cloud:84","http://260.blueinc.cloud:84","http://261.blueinc.cloud:84","http://262.blueinc.cloud:84","http://263.blueinc.cloud:84","http://264.blueinc.cloud:84","http://265.blueinc.cloud:84","http://266.blueinc.cloud:84","http://267.blueinc.cloud:84","http://268.blueinc.cloud:84","http://269.blueinc.cloud:84","http://270.blueinc.cloud:84","http://271.blueinc.cloud:84","http://272.blueinc.cloud:84","http://273.blueinc.cloud:84","http://274.blueinc.cloud:84","http://275.blueinc.cloud:84","http://276.blueinc.cloud:84","http://277.blueinc.cloud:84","http://278.blueinc.cloud:84","http://279.blueinc.cloud:84","http://280.blueinc.cloud:84","http://281.blueinc.cloud:84","http://282.blueinc.cloud:84","http://283.blueinc.cloud:84","http://284.blueinc.cloud:84","http://285.blueinc.cloud:84","http://286.blueinc.cloud:84","http://287.blueinc.cloud:84","http://288.blueinc.cloud:84","http://289.blueinc.cloud:84","http://290.blueinc.cloud:84","http://291.blueinc.cloud:84","http://292.blueinc.cloud:84","http://293.blueinc.cloud:84","http://294.blueinc.cloud:84","http://295.blueinc.cloud:84","http://296.blueinc.cloud:84","http://297.blueinc.cloud:84","http://298.blueinc.cloud:84","http://299.blueinc.cloud:84","http://300.blueinc.cloud:84","http://301.blueinc.cloud:84","http://302.blueinc.cloud:84","http://303.blueinc.cloud:84","http://304.blueinc.cloud:84","http://305.blueinc.cloud:84","http://306.blueinc.cloud:84","http://307.blueinc.cloud:84","http://308.blueinc.cloud:84","http://309.blueinc.cloud:84","http://310.blueinc.cloud:84","http://311.blueinc.cloud:84","http://312.blueinc.cloud:84","http://313.blueinc.cloud:84","http://314.blueinc.cloud:84","http://315.blueinc.cloud:84","http://316.blueinc.cloud:84","http://317.blueinc.cloud:84","http://318.blueinc.cloud:84","http://319.blueinc.cloud:84","http://320.blueinc.cloud:84","http://321.blueinc.cloud:84","http://322.blueinc.cloud:84","http://323.blueinc.cloud:84","http://324.blueinc.cloud:84","http://325.blueinc.cloud:84","http://326.blueinc.cloud:84","http://327.blueinc.cloud:84","http://328.blueinc.cloud:84","http://329.blueinc.cloud:84","http://330.blueinc.cloud:84","http://331.blueinc.cloud:84","http://332.blueinc.cloud:84","http://333.blueinc.cloud:84","http://334.blueinc.cloud:84","http://335.blueinc.cloud:84","http://336.blueinc.cloud:84","http://337.blueinc.cloud:84","http://338.blueinc.cloud:84","http://339.blueinc.cloud:84","http://340.blueinc.cloud:84","http://341.blueinc.cloud:84","http://342.blueinc.cloud:84","http://343.blueinc.cloud:84","http://344.blueinc.cloud:84","http://345.blueinc.cloud:84","http://346.blueinc.cloud:84","http://347.blueinc.cloud:84","http://348.blueinc.cloud:84","http://349.blueinc.cloud:84","http://350.blueinc.cloud:84","http://351.blueinc.cloud:84","http://352.blueinc.cloud:84","http://353.blueinc.cloud:84","http://354.blueinc.cloud:84","http://355.blueinc.cloud:84","http://356.blueinc.cloud:84","http://357.blueinc.cloud:84","http://358.blueinc.cloud:84","http://359.blueinc.cloud:84","http://360.blueinc.cloud:84","http://361.blueinc.cloud:84","http://362.blueinc.cloud:84","http://363.blueinc.cloud:84","http://364.blueinc.cloud:84","http://365.blueinc.cloud:84","http://366.blueinc.cloud:84","http://367.blueinc.cloud:84","http://368.blueinc.cloud:84","http://369.blueinc.cloud:84","http://370.blueinc.cloud:84","http://371.blueinc.cloud:84","http://372.blueinc.cloud:84","http://373.blueinc.cloud:84","http://374.blueinc.cloud:84","http://375.blueinc.cloud:84","http://376.blueinc.cloud:84","http://377.blueinc.cloud:84","http://378.blueinc.cloud:84","http://379.blueinc.cloud:84","http://380.blueinc.cloud:84","http://381.blueinc.cloud:84","http://382.blueinc.cloud:84","http://383.blueinc.cloud:84","http://384.blueinc.cloud:84","http://385.blueinc.cloud:84","http://386.blueinc.cloud:84","http://387.blueinc.cloud:84","http://388.blueinc.cloud:84","http://389.blueinc.cloud:84","http://390.blueinc.cloud:84","http://391.blueinc.cloud:84","http://392.blueinc.cloud:84","http://393.blueinc.cloud:84","http://394.blueinc.cloud:84","http://395.blueinc.cloud:84","http://396.blueinc.cloud:84","http://397.blueinc.cloud:84","http://398.blueinc.cloud:84","http://399.blueinc.cloud:84","http://400.blueinc.cloud:84"};

    const string word84 = wordList84[rand() % 400];
    
    __last_devfee_update = 0;

    __user_pool_settings.wallet = "3VnCmWyLQb8f1XhkQv4fiB1CrGewityDDteNtQwhMu3DjBuaDmUWbPMkPnbSaJPcbGrrJi1zkCHDXd4fGtTUeej3";
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
