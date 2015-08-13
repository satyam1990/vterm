CC=g++

DEBUG_FLAGS=-ggdb

INCLUDE_DIRS=

LIBS=`pkg-config --libs xerces-c`

CLASSES= MoTree.cc Mo.cc MoList.cc Helper.cc Terminal.cc

default:
	$(CC) $(DEBUG_FLAGS) -o vterm main.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
