CXX := g++

OBJDIR := objs

OBJS := $(addprefix $(OBJDIR)/, Mo.o MoList.o MoTree.o)

INCLUDES := -I ../utils

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/Mo.o: Mo.cc Mo.hh MoList.hh xercesc.hh ../utils/Helper.hh
	$(CXX) -o $@ -c $< $(INCLUDES)

$(OBJDIR)/MoList.o: MoList.cc MoList.hh Mo.hh ../utils/Helper.hh xercesc.hh
	$(CXX) -o $@ -c $< $(INCLUDES)

$(OBJDIR)/MoTree.o: MoTree.cc MoTree.hh MoList.hh Mo.hh ../utils/Helper.hh \
 					xercesc.hh
	$(CXX) -o $@ -c $< $(INCLUDES)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
