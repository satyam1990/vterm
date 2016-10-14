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

$(BINDIR):
	mkdir $(BINDIR)

clean:
	$(foreach dir, $(DIRS), cd $(dir); make clean; cd ..;)
	rm -rf $(BINDIR)
