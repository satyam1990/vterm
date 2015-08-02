CC=g++

INCLUDE_DIRS= -I ../../

LIBS=`pkg-config --libs xerces-c`

CLASSES= ../../MoTree.cc ../../Mo.cc ../../MoList.cc

default:
	$(CC) -o testMoTree testMoTree.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
