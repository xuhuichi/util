BIN = ../bin/testmain
cpp = g++
cc = gcc
LIBS =  -lpthread
CFLAGS = -g
CPPFLAGS = -g -Wall -std=c++0x 

SRC_DIR = ./
OBJ_DIR = ../obj/
#依赖的头文件路径
LIB_INCLUDE_DIR = ../include
DEFINC = $(addprefix -I, $(LIB_INCLUDE_DIR))

#C文件路径
LIB_C_SOURCE_DIRS = .

#C++文件路径
LIB_CPP_SOURCE_DIRS = .

#C和C++文件列表
get_sources_from_directory = $(wildcard $1/*.c) 
get_sources_from_directory1 = $(wildcard $1/*.cpp) 
get_sources = $(foreach dir, $1, $(call get_sources_from_directory,$(dir)))
get_sources1 = $(foreach dir, $1, $(call get_sources_from_directory1,$(dir)))
CSRCS = $(call get_sources,$(LIB_C_SOURCE_DIRS))
CPPSRCS = $(call get_sources1,$(LIB_CPP_SOURCE_DIRS))


#所有的.o文件列表
CPPOBJS := $(CPPSRCS:.cpp=.o)
COBJS := $(CSRCS:.c=.o)


$(BIN) : $(COBJS) $(CPPOBJS)
	$(cpp) -o $@ $(COBJS) $(CPPOBJS) $(LIBS)
	@echo "生成${BIN}执行文件成功"

$(COBJS) : %.o : %.c	
	$(cc) -c $< -o $@ $(DEFINC) $(CFLAGS)


$(CPPOBJS) : %.o : %.cpp
	$(cpp) -c $< -o $@ $(DEFINC) $(CPPFLAGS)

.PHONY: clean

clean: 
	-rm $(BIN) $(COBJS) $(CPPOBJS)


