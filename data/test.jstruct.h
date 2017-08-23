#ifndef TEST_H
#define TEST_H

#include <stdint.h>
#include <stdbool.h>
#include <jstruct/error.h>

//@json
struct _i2c {
    int busnum;
    int fh;
    int addr;
    uint32_t funcs;
//    void* handle;
//    void* advance_func;
};

//@json
struct my_json_i2c {
    // import all the members of foreign_struct so that this struct definition matches it.
    // @inline
    struct _i2c dev;
};

//@json
struct my_json_data {
    /*
    @schema {
        "title": "Identifier",
        "description": "unique object id",
        "type": "int"
    }
    */
#ifndef DONT_USE_UINT64_T_FOR_SOME_REASON
    uint64_t id;
#else
    unsigned long long id;
#endif
    /* don't include in json */
    //@private
    int _id;
    // treated as uintX where X is the sizeof the enum
    enum jstruct_error err;

    bool active;

    /* add the ability to null this field even though it's not a pointer */
    //@nullable
    //@name ratio
    double ratio_double;
    //@name other_name
    char *name;
    unsigned long long ull;
    /* TODO: @dereference annotation in case this isn't an array? */
    char **tags;
};

//@json
struct my_json_basic_container {
    struct my_json_data main_data;
};

//@json
struct my_json_container {
    struct my_json_data main_data;

    /* static arrays are automatic */
    struct my_json_data array_data[5];

    /* TODO: @array shouldn't be automatic here or add @single or @deferefence annotation? */
    struct my_json_data *alloc_array_data;
};

#endif // TEST_H
