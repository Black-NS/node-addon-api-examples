SUBDIRS = hello \
			hello_class \

.SILENT : all build run clean

all : build run

build : 
	for DIRS in $(SUBDIRS); do \
	$(MAKE) -C $$DIRS clean build; \
	done

run :
	for DIRS in $(SUBDIRS); do \
	$(MAKE) -C $$DIRS run; \
	done

clean :
	for DIRS in $(SUBDIRS); do \
	$(MAKE) -C $$DIRS clean; \
	done
