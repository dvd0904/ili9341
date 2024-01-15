CXX := /usr/local/linaro/gcc-linaro-7.5.0-2019.12-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-g++
# CXX := g++
CXXFLAGS :=-I./ -I./include/

shared_cc := $(wildcard shared/*.cc)
shared_o  := $(shared_cc:.cc=.o)

main: ${shared_o} main.cc
	${CXX} ${CXXFLAGS} $^ -o $@

shared/%.o: shared/%.cc
	${CXX} ${CXXFLAGS} -fPIC -c $^ -o $@

.PHONY: main

clean: 
	rm -rf main 
	rm -rf ${shared_o}

