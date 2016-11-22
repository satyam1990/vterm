CXX := g++

INCLUDES := -I ../utils

OBJDIR := objs

BINDIR := bin

OBJS :=  $(addprefix $(OBJDIR)/, AlarmInitiator.o main.o)

HELPER_OBJ := ../utils/$(OBJDIR)/*.o

$(BINDIR)/alarmInitiator: $(OBJS) | $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(HELPER_OBJ) $(INCLUDES) $(LIBS) $(CXXFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/AlarmInitiator.o: AlarmInitiator.cc AlarmInitiator.hh ../utils/Helper.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR)/main.o: main.cc AlarmInitiator.hh ../utils/Helper.hh
	$(CXX) -ggdb -o $@ -c $<  $(INCLUDES)

$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR):
	mkdir $(BINDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)
