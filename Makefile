CXX = g++

DEBUG_FLAGS = -ggdb

LIBS = `pkg-config --libs xerces-c`

default:
	cd cmd_handler; make
	cd utils; make

clean:
	rm -rf vterm
