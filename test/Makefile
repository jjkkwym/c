ROOT_DIR := ..
BUILD_DIR := $(ROOT_DIR)/build
LIB_DIR := $(ROOT_DIR)/library

cjson_test: cjson_test.c
	mkdir -p $(BUILD_DIR)
	gcc -o $@ $> -L$(LIB_DIR)/libmisc.a -Iinc -lcrypto -lssl -lpthread