CC=g++

INCLUDE_DIRS= -I../../mo_parser -I../../utils

LIBS=`pkg-config --libs xerces-c`

CLASSES= ../../mo_parser/*.cc ../../utils/Helper.cc

default:
	$(CC) -o testMoList testMoList.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
