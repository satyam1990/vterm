CC=clang++

INCLUDE_DIRS= -I ../../mo_parser \
			  -I../../utils

LIBS=`pkg-config --libs xerces-c`

CLASSES= ../../mo_parser/MoTree.cc ../../mo_parser/Mo.cc ../../mo_parser/MoList.cc ../../utils/Helper.cc

default:
	$(CC) -o testMoTree testMoTree.cc $(CLASSES) $(INCLUDE_DIRS) $(LIBS)
