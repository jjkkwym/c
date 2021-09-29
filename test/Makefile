ROOT_DIR := ..
BUILD_DIR := build

INC_DIR := -I$(ROOT_DIR)/inc
LIB_DIR := -L$(ROOT_DIR)/lib
LIB := -lmisc -lcrypto -lssl -lpthread
CFLAG := -g -Wall
LDFLAG := $(INC_DIR) $(LIB_DIR) $(LIB)

$(shell mkdir -p $(BUILD_DIR))

.PHONY: all misc

all:misc $(BUILD_DIR)/cjson_test 

misc:
	make -C $(ROOT_DIR)/lib/misc

$(BUILD_DIR)/cjson_test: cjson_test.c
	gcc -o $(BUILD_DIR)/$@ $< $(CFLAG) $(LDFLAG)