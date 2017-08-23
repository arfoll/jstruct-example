#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include <mraa.h>

#include JSON_OBJECT_H

#include "data/test.h"

struct my_json_data make_data() {
    static int id = 0;
    static char *data_tags[] = {"main", "data", "sample"};
    struct my_json_data data = {
        .id=1,
        ._id=++id,
        .ratio_double=3.5,
        .active=true,
        .name="main_data",
        .ull=24,
        .tags=data_tags,
        .tags__length__=3,
    };
    return data;
}

int main() {
    struct my_json_data data = make_data();
    /* malloc macro (automatically sets container.array_data__length__ = 2) */
    // jstruct_array_malloc(container, alloc_array_data, struct my_json_data, 2);

    struct json_object *obj = jstruct_export(&data, my_json_data);
    if (obj) {
        printf("%s", json_object_to_json_string(obj));
    }

    mraa_i2c_context dev = mraa_i2c_init(0+512);
    if (dev == NULL) {
        printf("failed to init i2c\n");
	return 1;
    }
    struct _i2c convdev = (struct _i2c) *dev;
    struct json_object *obj2 = jstruct_export(&convdev, _i2c);
    if (obj2) {
        printf("%s", json_object_to_json_string(obj2));
    }
}
