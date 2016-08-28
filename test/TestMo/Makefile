CC=g++

INCLUDE_DIRS= -I ../../

LIBS=`pkg-config --libs xerces-c`

CLASSES= ../../MoTree.cc ../../Mo.cc ../../MoList.cc ../../Helper.cc

default:
	$(CC) -o testMo testMo.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
