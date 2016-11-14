CXX := g++

CXXFLAGS := 

INCLUDES := -I../utils

LIBS := `pkg-config gtk+-2.0 --cflags --libs`

BINDIR := bin

OBJDIR := objs

OBJS := $(addprefix $(OBJDIR)/, MainWindow.o EventHandler.o  main.o)

HELPER_OBJ := ../utils/$(OBJDIR)/*.o

$(BINDIR)/main: $(OBJS) | $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(HELPER_OBJ) $(INCLUDES) $(LIBS) $(CXXFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/MainWindow.o: MainWindow.cc MainWindow.hh EventHandler.hh ../utils/Helper.hh
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBS) $(CXXFLAGS)

$(OBJDIR)/EventHandler.o: EventHandler.cc EventHandler.hh
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBS) $(CXXFLAGS)

$(OBJDIR)/main.o: main.cc MainWindow.hh EventHandler.hh ../utils/Helper.hh
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBS) $(CXXFLAGS)

$(BINDIR):
	mkdir $(BINDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)
