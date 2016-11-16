CXX = /vobs/ossrc_3pp/freeware/studio11/SUNWspro/bin/CC

OBJS = MainWindow.o EventHandler.o main.o

HELPER_OBJ = ../utils/*.o

INCLUDES = -I../utils

LIBS = `pkg-config gtk+-2.0 --cflags --libs`

main: $(OBJS)
	$(CXX) -o $@ $(OBJS) $(HELPER_OBJ) $(INCLUDES) $(LIBS)

MainWindow.o: MainWindow.cc MainWindow.hh EventHandler.hh ../utils/Helper.hh
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBS)

EventHandler.o: EventHandler.cc EventHandler.hh MainWindow.hh
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBS)

main.o: main.cc MainWindow.hh EventHandler.hh ../utils/Helper.hh
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBS)

.PHONY: clean
clean:
	rm -rf *.o main
