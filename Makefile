BUILD_DIR := build
TARGET := $(BUILD_DIR)/demo

all: library $(TARGET)

$(TARGET): main.c
	mkdir -p $(BUILD_DIR)
	gcc -o $(TARGET) main.c library/libmisc.a -Iinc -lcrypto -lssl -lpthread

library:
	make -C library

run:
	./$(TARGET)