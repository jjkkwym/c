BUILD_DIR := build
TARGET := $(BUILD_DIR)/demo
LIB_DIR := -L lib
LIB := -lmisc -lcrypto -lssl -lpthread
INC_DIR := inc
INCLUDE := -I$(INC_DIR)
CFLAG := -g -Wall

.PHONY: all misc clean run

all: misc $(TARGET)

$(TARGET): main.c
	mkdir -p $(BUILD_DIR)
	gcc -o $(TARGET) main.c $(CFLAG) $(INCLUDE) $(LIB_DIR) $(LIB)

misc:
	make -C misc

clean:
	rm $(TARGET)

run:
	./$(TARGET)