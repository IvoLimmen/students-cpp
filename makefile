src_files = main.cpp student.cpp course.cpp

all: clean build

clean:
	rm -rf bin
	mkdir bin

build:
	g++ -std=c++17 $(src_files) -o bin/students
