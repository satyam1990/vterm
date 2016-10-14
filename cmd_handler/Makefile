CXX := g++

INCLUDES := -I ../mo_parser \
			-I ../utils

OBJDIR := objs

OBJS :=  $(addprefix $(OBJDIR)/, Terminal.o MMLProcessor.o APLOCProcessor.o \
		Response.o MMLResponse.o APLOCResponse.o)

all: $(OBJS) 

$(OBJS): | $(OBJDIR)

$(OBJDIR)/Terminal.o: Terminal.cc Terminal.hh MMLProcessor.hh MMLResponse.hh \
 						Response.hh ../utils/Helper.hh APLOCProcessor.hh \
						../mo_parser/MoTree.hh ../mo_parser/MoList.hh \
						../mo_parser/Mo.hh ../mo_parser/xercesc.hh \
 						../mo_parser/MoList.hh ../mo_parser/Mo.hh \
						APLOCResponse.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR)/MMLProcessor.o: MMLProcessor.cc MMLProcessor.hh MMLResponse.hh \
 							Response.hh ../utils/Helper.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR)/APLOCProcessor.o: APLOCProcessor.cc APLOCProcessor.hh \
 							../mo_parser/MoTree.hh ../mo_parser/MoList.hh \
							../mo_parser/Mo.hh ../utils/Helper.hh ../mo_parser/xercesc.hh \
							../mo_parser/MoList.hh \
 							../mo_parser/Mo.hh APLOCResponse.hh Response.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR)/Response.o: Response.cc Response.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR)/MMLResponse.o: MMLResponse.cc MMLResponse.hh Response.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR)/APLOCResponse.o: APLOCResponse.cc APLOCResponse.hh Response.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
