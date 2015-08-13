CC=clang

INCLUDE_DIRS= -I ../../

LIBS=`pkg-config --libs xerces-c`

CLASSES= ../../MoTree.cc ../../Mo.cc ../../MoList.cc ../../Helper.cc

default:
	$(CC) -o testMoTree testMoTree.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
