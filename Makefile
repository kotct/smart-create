PROJECT_NAME=smart-create
PROJECT_SHORT_BINARY_NAME=smc

CXX=gcc

GENERAL_FLAGS=-ggdb -lm -std=c11 -D_POSIX_SOURCE

COMPILE_FLAGS=-fPIC $(GENERAL_FLAGS)
ASSEMBLY_FLAGS=-fPIC $(GENERAL_FLAGS)
LINK_FLAGS=-pie $(GENERAL_FLAGS)

MODNAMES_H_OUTPUT=$(shell ./build/modulenames.sh h)
MODNAMES_C_OUTPUT=$(shell ./build/modulenames.sh c)

HEADERS=$(patsubst %,src/%.h,$(MODNAMES_H_OUTPUT))
ASSEMBLY=$(patsubst %,asm/%.s,$(MODNAMES_C_OUTPUT))
OBJECTS=$(patsubst %,obj/%.o,$(MODNAMES_C_OUTPUT))

PROGRAM_FILE=$(PROJECT_SHORT_BINARY_NAME)

all: $(PROGRAM_FILE)

include ./build/modules.mk
include ./build/smc.mk
include ./build/clean.mk
