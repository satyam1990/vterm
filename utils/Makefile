CXX := g++

OBJDIR := OBJS

OBJS:= $(addprefix $(OBJDIR)/, Helper.o)

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/Helper.o: Helper.cc Helper.hh
	$(CXX) -o $@ -c $<

$(OBJDIR):
	mkdir $(OBJDIR)
