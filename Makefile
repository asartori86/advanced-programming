# Simple Makefile to compile all the sample codes provided during the
# course of Advanced Programming

FNAMES = 01_intro 02_arrays
FOLDERS = $(addprefix lectures/, $(FNAMES))


all:
	@for i in $(FOLDERS);do cd $$i; make; cd -; done

clean: 
	@for i in $(FOLDERS);do cd $$i; make clean; cd -; done
	@find . -type f -name '*~' -exec rm '{}' \;

format: 
	@for i in $(FOLDERS);do cd $$i; make format; cd -; done 

.PHONY: all clean format

