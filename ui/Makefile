CXX := g++

CXXFLAGS := -std=c++11

LIBS := `pkg-config gtkmm-2.4 --cflags --libs`

BINDIR := bin

OBJDIR := objs

OBJS := $(addprefix $(OBJDIR)/, MainWindow.o main.o)

$(BINDIR)/main: $(OBJS) | $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(LIBS) $(CXXFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/MainWindow.o: MainWindow.cc MainWindow.hh
	$(CXX) -o $@ -c $< $(LIBS) $(CXXFLAGS)

$(OBJDIR)/main.o: main.cc MainWindow.hh
	$(CXX) -o $@ -c $< $(LIBS) $(CXXFLAGS)

$(BINDIR):
	mkdir $(BINDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)