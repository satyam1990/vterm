CXX = /vobs/ossrc_3pp/freeware/studio11/SUNWspro/bin/CC

LIBDIR = -L/vobs/ossrc_3pp/cif_3pp/borland_enterprise_server/lib

DEBUG_FLAGS = -ggdb

LIBS = -lxerces-c_2_7

BINDIR = bin

DIRS = cmd_handler utils mo_parser

INCLUDES = -I/vobs/ossrc_3pp/cif_3pp/borland_enterprise_server/include \
			-Icmd_handler \
			-Iutils \
			-Imo_parser

OBJS = cmd_handler/*.o utils/*.o mo_parser/*.o

vterm: subdirs
	$(CXX) -o $@ main.cc $(OBJS) $(INCLUDES) $(LIBDIR) $(LIBS)
	@echo "\nCompilation Successful!"

subdirs:
	@for dir in $(DIRS); do \
		cd $$dir; $(MAKE) -f Makefile.sol; cd ..; \
		if [ $$? -ne 0 ]; then \
			exit 1; \
		fi; \
	done

clean:
	@for dir in $(DIRS); do \
		cd $$dir; $(MAKE) -f Makefile.sol clean; cd ..; \
	done
	rm -rf vterm
