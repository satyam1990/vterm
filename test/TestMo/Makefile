CC=g++

INCLUDE_DIRS= -I../../cmd_handler -I../../utils -I../../mo_parser

LIBS=`pkg-config --libs xerces-c`

CLASSES= ../../mo_parser/*.cc ../../utils/Helper.cc

default:
	$(CC) -o testMo testMo.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
