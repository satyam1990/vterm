CXX = /proj/wipba/eam/dev_tools/gcc5/bin/g++

OBJS = MainWindow.o main.o 

INCLUDES = -I/proj/wipba/eam/dev_tools/include/gtkmm-2.4 \
			-I/proj/wipba/eam/dev_tools/lib/gtkmm-2.4/include \
			-I/proj/wipba/eam/dev_tools/include/atkmm-1.6 \
			-I/proj/wipba/eam/dev_tools/include/giomm-2.4 \
			-I/proj/wipba/eam/dev_tools/lib/giomm-2.4/include \
			-I/proj/wipba/eam/dev_tools/include/pangomm-1.4 \
			-I/proj/wipba/eam/dev_tools/lib/pangomm-1.4/include \
			-I/proj/wipba/eam/dev_tools/include/gtk-2.0 \
			-I/proj/wipba/eam/dev_tools/include/gtk-unix-print-2.0 \
			-I/proj/wipba/eam/dev_tools/include/gdkmm-2.4 \
			-I/proj/wipba/eam/dev_tools/lib/gdkmm-2.4/include \
			-I/proj/wipba/eam/dev_tools/include/atk-1.0 \
			-I/proj/wipba/eam/dev_tools/include/glibmm-2.4 \
			-I/proj/wipba/eam/dev_tools/lib/glibmm-2.4/include \
			-I/proj/wipba/eam/dev_tools/include/glib-2.0 \
			-I/proj/wipba/eam/dev_tools/lib/glib-2.0/include \
			-I/proj/wipba/eam/dev_tools/include/sigc++-2.0 \
			-I/proj/wipba/eam/dev_tools/lib/sigc++-2.0/include \
			-I/proj/wipba/eam/dev_tools/include/cairomm-1.0 \
			-I/proj/wipba/eam/dev_tools/lib/cairomm-1.0/include \
			-I/proj/wipba/eam/dev_tools/include/pango-1.0 \
			-I/proj/wipba/eam/dev_tools/include/cairo \
			-I/proj/wipba/eam/dev_tools/lib/gtk-2.0/include \
			-I/proj/wipba/eam/dev_tools/include/gdk-pixbuf-2.0 \
			-I/proj/wipba/eam/dev_tools/include/freetype2 \
			-I/proj/wipba/eam/dev_tools/include

LIBDIR = /proj/wipba/eam/dev_tools/lib

LIBS = -lgtkmm-2.4 -latkmm-1.6 -lgdkmm-2.4 -lgiomm-2.4 -lpangomm-1.4 \
		-lgtk-x11-2.0 -lglibmm-2.4 -lcairomm-1.0 -lsigc-2.0 -lgdk-x11-2.0 \
		-latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 \
		-lcairo -lpango-1.0 -lfreetype -lfontconfig -lgobject-2.0 -lglib-2.0 -lintl

main: $(OBJS)
	$(CXX) -o $@ $< $(INCLUDES) $(LIBDIR) $(LIBS)

MainWindow.o:
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBDIR) $(LIBS)

main.o:
	$(CXX) -o $@ -c $< $(INCLUDES) $(LIBDIR) $(LIBS)

.PHONY: clean
clean:
	rm -rf *.o
