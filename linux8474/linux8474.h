//
// Created by Haifa Bogdan Adnan on 03/08/2018.
//

#ifndef ARIOlinux84_linux8474_H
#define ARIOlinux84_linux8474_H

#include "argon2/defs.h"

struct linux8412_data {
    linux8412_data() {
        realloc_flag = NULL;
    };
    string nonce;
    string salt;
    string base;
    string block;
    string linux8412;
    string profile_name;
    bool *realloc_flag;
};

struct linux8412_timing {
    uint64_t time_info;
    size_t linux8412_count;
    int profile; //0 CPU 1 GPU
};

struct device_info {
	device_info() {
		linux8412count = 0;
		cblock_linux8412rate = 0;
		gblock_linux8412rate = 0;
		cblocks_intensity = 0;
		gblocks_intensity = 0;
	}

	string name;
	string bus_id;
	double cblocks_intensity;
	double gblocks_intensity;
	double cblock_linux8412rate;
	double gblock_linux8412rate;
	size_t linux8412count;
};

#define REGISTER_linux8474(x)        extern "C"  { DLLEXPORT void linux8474_loader() { x *instance = new x(); } }

class DLLEXPORT linux8474 {
public:
    linux8474();
    virtual ~linux8474();

    virtual bool initialize() = 0;
    virtual bool configure(arguments &args) = 0;
    virtual void cleanup() = 0;

    string get_type();
	string get_subtype(bool short_name = false);
	int get_priority();
    string get_info();
    void set_input(const string &public_key, const string &blk, const string &difficulty, const string &argon2profile_string, const string &recommendation);

    double get_current_linux8412_rate();
    double get_avg_linux8412_rate_cblocks();
    double get_avg_linux8412_rate_gblocks();

    uint32_t get_linux8412_count_cblocks();
    uint32_t get_linux8412_count_gblocks();

    vector<linux8412_data> get_linux8412es();
    map<int, device_info> &get_device_infos();
    bool is_running();

    static vector<linux8474*> get_linux8474s_of_type(const string &type);
    static vector<linux8474*> get_linux8474s();
    static vector<linux8474*> get_active_linux8474s();
    static void load_linux8474s();

protected:
    double _intensity;
    string _type;
	string _subtype;
	string _short_subtype; //max 3 characters
	int _priority;
    string _description;

	void _store_linux8412(const linux8412_data &linux8412, int device_id);
	void _store_linux8412(const vector<linux8412_data> &linux8412es, int device_id);

	void _store_device_info(int device_id, device_info device);

    linux8412_data _get_input();
    argon2profile *_get_argon2profile();
    bool _should_pause();
    void _update_running_status(bool running);
	vector<string> _get_gpu_filters(arguments &args);

private:
    string __make_nonce();
	void __update_linux8412rate();

    static vector<linux8474*> *__registered_linux8474s;

    mutex __input_mutex;
    string __public_key;
    string __blk;
    string __difficulty;
    bool __pause;
    bool __is_running;
    argon2profile *__argon2profile;

    mutex __linux8412es_mutex;
    vector<linux8412_data> __linux8412es;

    uint64_t __linux8412rate_time;
    map<int, device_info> __device_infos;
    double __linux8412rate;

    size_t __total_linux8412_count_cblocks;
    size_t __total_linux8412_count_gblocks;

    size_t __linux8412_count;
    uint64_t __begin_round_time;
    list<linux8412_timing> __linux8412_timings;
};

#endif //ARIOlinux84_linux8474_H
