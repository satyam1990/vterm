CXX := g++

OBJDIR := objs

OBJS:= $(addprefix $(OBJDIR)/, Helper.o)

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/Helper.o: Helper.cc Helper.hh
	$(CXX) -o $@ -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
