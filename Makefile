PROJECT_NAME=smart-create
PROJECT_SHORT_BINARY_NAME=smc

CXX=gcc
MAKE=make

MULTILIB_LOCATION=./lib/multilib
MULTILIB_LIBRARY_FILE=$(MULTILIB_LOCATION)/multilib.so

GENERAL_FLAGS=-ggdb -lm -std=gnu11 -D_POSIX_SOURCE

COMPILE_FLAGS=-fPIC $(GENERAL_FLAGS) -I$(MULTILIB_LOCATION) -I$(MULTILIB_LOCATION)
LINK_FLAGS=-pie $(GENERAL_FLAGS) -L$(MULTILIB_LOCATION) $(MULTILIB_LIBRARY_FILE)

MODNAMES_H_OUTPUT=$(shell ./build/modulenames.sh h)
MODNAMES_C_OUTPUT=$(shell ./build/modulenames.sh c)

HEADERS=$(patsubst %,src/%.h,$(MODNAMES_H_OUTPUT))
ASSEMBLY=$(patsubst %,asm/%.s,$(MODNAMES_C_OUTPUT))
OBJECTS=$(patsubst %,obj/%.o,$(MODNAMES_C_OUTPUT))

PROGRAM_FILE=$(PROJECT_SHORT_BINARY_NAME)

all: $(PROGRAM_FILE)

include ./build/clean.mk
include ./build/modules.mk
include ./build/multilib.mk
include ./build/smc.mk
