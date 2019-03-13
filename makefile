MAKEFLAGS += Rr

TARGET := main.app

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.app *.o

$(TARGET): main.o rb.o norm.o node.o rng.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c -Wall -Wextra -Wpedantic -Wshadow -std=c++11 $< -o $@

main.o: main.cpp common.hpp node.hpp norm.hpp rb.hpp rng.hpp
node.o: node.cpp node.hpp
norm.o: norm.cpp common.hpp node.hpp
rb.o: rb.cpp common.hpp node.hpp
rng.o: rng.cpp common.hpp node.hpp norm.hpp

