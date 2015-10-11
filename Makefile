CXX = clang++
FLAGS = -std=c++11
INCLUDE = -I/usr/local/opt/openssl/include -I/usr/local/opt/boost/include -I/usr/local/opt/cpp-netlib/include
LIB = -L/usr/local/opt/openssl/lib -L/usr/local/opt/boost/lib -L/usr/local/opt/cpp-netlib/lib
all: site
clean:
	rm -fr build/*
site:
	$(CXX) $(FLAGS) $(INCLUDE) $(LIB) src/main.cc -o build/myserver

.PHONY: all clean site
