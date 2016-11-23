CXX := g++

DEBUG_FLAGS := -ggdb

LIBS := `pkg-config --libs xerces-c`

BINDIR := bin

DIRS := cmd_handler utils mo_parser

INCLUDES := $(addprefix -I , $(DIRS))

OBJS := $(addsuffix /objs/*.o, $(DIRS))

$(BINDIR)/vterm: subdirs | $(BINDIR)
	$(CXX) $(DEBUG_FLAGS) -o $@ main.cc $(OBJS) $(INCLUDES) $(LIBS)
	@echo -e "\nCompilation Successful!"

subdirs:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir; \
		if [ $$? -ne 0 ]; then \
			exit 1; \
		fi; \
	done
	# make the ui and alarm initiator code separately
	$(MAKE) -C ui
	$(MAKE) -C alarm_initiator


install:
	rm -rf wans
	mkdir wans
	mkdir wans/bin
	mkdir wans/etc
	mkdir wans/mml_command_output
	cp $(BINDIR)/vterm deps/emt_tgw_telnetd ui/$(BINDIR)/main  wans/bin
	cp ui/scripts/* wans/bin
	cp alarm_initiator/$(BINDIR)/alarmInitiator wans/bin
	cp etc/scripts/launch_gui.sh wans
	cp etc/mo.xml wans/etc
	tar -cvf wans.tar wans
	rm -rf wans
	@echo -e "\nWANS Tarball Successfully prepared!"

$(BINDIR):
	mkdir $(BINDIR)

clean:
	$(foreach dir, $(DIRS), cd $(dir); make clean; cd ..;)
	$(MAKE) clean -C ui
	$(MAKE) clean -C alarm_initiator
	rm -rf $(BINDIR) wans.tar
