CXX := g++
CXXFLAGS :=-I./ -I./include/

main: main.cc sysinfo.o
	${CXX} ${CXXFLAGS} $^ -o $@

.PHONY: main

sysinfo.o: sysinfo.cc
	${CXX} ${CXXFLAGS} -fPIC -c $^ -o $@

clean: 
	rm -rf main 
	rm -rf *.o

