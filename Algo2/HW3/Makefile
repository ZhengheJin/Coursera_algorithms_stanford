#Makefile for hw01
#This file traverses the subdirecties and runs "make" in each one

SUBDIRS = 1 2

.PHONY: subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

# The following ensures that the problems will be executed in order

2: 1
