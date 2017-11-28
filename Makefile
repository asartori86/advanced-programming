# Simple Makefile to compile all the sample codes provided during the
# course of Advanced Programming

all:
	+$(MAKE) $@ -C lectures/01_intro
	+$(MAKE) $@ -C lectures/02_arrays
	+$(MAKE) $@ -C lectures/03_classes
	+$(MAKE) $@ -C lectures/04_error_handling
	+$(MAKE) $@ -C lectures/05_constructors
	+$(MAKE) $@ -C lectures/06_inheritance
	+$(MAKE) $@ -C lectures/07_iterators

clean: 
	+$(MAKE) $@ -C lectures/01_intro
	+$(MAKE) $@ -C lectures/02_arrays
	+$(MAKE) $@ -C lectures/03_classes
	+$(MAKE) $@ -C lectures/04_error_handling
	+$(MAKE) $@ -C lectures/05_constructors
	+$(MAKE) $@ -C lectures/06_inheritance
	+$(MAKE) $@ -C lectures/07_iterators
	@find . -type f -name '*~' -exec rm '{}' \;

format: 
	+$(MAKE) $@ -C lectures/01_intro
	+$(MAKE) $@ -C lectures/02_arrays
	+$(MAKE) $@ -C lectures/03_classes
	+$(MAKE) $@ -C lectures/04_error_handling
	+$(MAKE) $@ -C lectures/05_constructors
	+$(MAKE) $@ -C lectures/06_inheritance
	+$(MAKE) $@ -C lectures/07_iterators

.PHONY: all clean format
