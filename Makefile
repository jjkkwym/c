BUILD_DIR := build
TARGET := $(BUILD_DIR)/demo
INC_DIR := -Iinc
LIB_DIR := -Llib
LIB := -lmisc -lcrypto -lssl -lpthread
CFLAG := -g -Wall
LDFLAG := $(INC_DIR) $(LIB_DIR) $(LIB)

.PHONY: all misc clean run

all: $(TARGET)

$(TARGET): main.c misc
	mkdir -p $(BUILD_DIR)
	gcc -o $(TARGET) main.c $(CFLAG) $(LDFLAG)

misc:
	make -C lib/misc

clean:
	rm $(TARGET)

run:
	./$(TARGET)