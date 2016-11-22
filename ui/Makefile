CXX := g++

CXXFLAGS := -ggdb

INCLUDES := -I../utils

LIBS := `pkg-config gtk+-2.0 --cflags --libs`

BINDIR := bin

OBJDIR := objs

OBJS := $(addprefix $(OBJDIR)/, MainWindow.o EventHandler.o \
			MoPathEditorDialog.o MmlPathEditorDialog.o  DdEditorDialog.o main.o)

HELPER_OBJ := ../utils/$(OBJDIR)/*.o

$(BINDIR)/main: $(OBJS) | $(BINDIR)
	$(CXX) -o $@ $(OBJS) $(HELPER_OBJ) $(INCLUDES) $(LIBS) $(CXXFLAGS)

$(OBJS): | $(OBJDIR)

$(OBJDIR)/MainWindow.o: MainWindow.cc MainWindow.hh EventHandler.hh ../utils/Helper.hh
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES) $(LIBS)

$(OBJDIR)/MoPathEditorDialog.o: MoPathEditorDialog.cc MoPathEditorDialog.hh ../utils/Helper.hh
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES) $(LIBS)

$(OBJDIR)/MmlPathEditorDialog.o: MmlPathEditorDialog.cc MmlPathEditorDialog.hh ../utils/Helper.hh
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES) $(LIBS)

$(OBJDIR)/EventHandler.o: EventHandler.cc EventHandler.hh MainWindow.hh MoPathEditorDialog.hh MmlPathEditorDialog.hh
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES) $(LIBS)

$(OBJDIR)/DdEditorDialog.o: DdEditorDialog.cc DdEditorDialog.hh ../utils/Helper.hh
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES) $(LIBS)

$(OBJDIR)/main.o: main.cc MainWindow.hh EventHandler.hh ../utils/Helper.hh
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES) $(LIBS)

$(BINDIR):
	mkdir $(BINDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)
