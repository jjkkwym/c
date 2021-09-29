ROOT_DIR  := ../..
INSTALL_LIB_DIR := ..
INSTALL_INC_DIR := $(ROOT_DIR)/inc

C_SRC += $(wildcard base64/*.c)
C_SRC += $(wildcard cJSON/*.c)
C_SRC += $(wildcard common/*.c)
C_SRC += $(wildcard list/*.c)
C_SRC += $(wildcard log/*.c)

HEADERS += $(wildcard base64/*.h)
HEADERS += $(wildcard cJSON/*.h)
HEADERS += $(wildcard common/*.h)
HEADERS += $(wildcard list/*.h)
HEADERS += $(wildcard log/*.h)

OBJS := $(patsubst %.c,%.o,$(C_SRC))
DEPS := $(patsubst %.c,%.d,$(C_SRC))

INCLUDES:= -I.
LIBS := -lpthread -lcrypto -lm
C_FLAGS := $(INCLUDES) $(LIBS)
C_FLAGS += -g -Wall

$(info C_SRC: $(C_SRC))
$(info OBJS: $(OBJS))
$(info DEPS: $(DEPS))

all: libmisc.a install

libmisc.a : $(OBJS)
	ar -rcs $@ $^

.c.o:
	$(CC) -o $@ -c $<  $(INCLUDE) $(C_FLAGS)
#-MM -MF $(patsubst %.o,%.d,$@)
clean:
	rm $(OBJS) libmisc.a

install : FORCE
	@mkdir -p $(INSTALL_INC_DIR)
	@mkdir -p $(INSTALL_LIB_DIR) 
	cp $(HEADERS) $(INSTALL_INC_DIR)
	cp libmisc.a  $(INSTALL_LIB_DIR)

FORCE:
#.c.o:
#$(TARGET):$(OBJS)
#	@echo $(C_SRC)
#	@echo $(LIBS)
#	@echo $(OBJS)
#	gcc -o $@ $^ $(LIBS) $(C_FLAGS)
#${OUTPUT_DIR}/%.o:%.c
#	mkdir -p build/
#	gcc -o $@ -g -c $< $(INCLUDE) $(LIBS) $(C_FLAGS) 
#clean:
#	rm -rf $(OUTPUT_DIR)
#run:
#	./build/demo
#-include $(DEPS)