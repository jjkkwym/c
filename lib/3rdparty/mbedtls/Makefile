ROOT_DIR  := ../../..
INSTALL_LIB_DIR := $(ROOT_DIR)/lib
INSTALL_INC_DIR := $(ROOT_DIR)/inc/mbedtls
HEADERS := include/mbedtls include/psa
LIBS := $(wildcard library/*.a)

all: mbedtls_lib install
	
mbedtls_lib:
	make -C library

install :
	@mkdir -p $(INSTALL_INC_DIR)
	@mkdir -p $(INSTALL_LIB_DIR)
	cp -r $(HEADERS) $(INSTALL_INC_DIR)
	cp -r $(LIBS)  $(INSTALL_LIB_DIR)