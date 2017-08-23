 ~/git/jstruct/parse/jstruct_parse.py data/test.jstruct.h ~/git/jstruct/util/fake_libc_include
gcc -g data/test.init.c test.c -ljson-c -ljstruct -DJSON_OBJECT_H="<json-c/json_object.h>"
