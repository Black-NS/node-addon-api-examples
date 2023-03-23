CC = node-gyp

TARGET = test.js

all: clean build run

clean :
	$(CC) clean

configure :
	$(CC) configure

build :
	$(CC) configure build

run :
	node $(TARGET)