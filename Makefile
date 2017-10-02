# Simple Makefile to compile all the sample codes provided during the
# course of Advanced Programming

all: L01

clean: C01

L01:
	$(info ***** Compiling codes of lecture 01 *****)
	@cd lectures/01_intro && make

C01:
	$(info ***** Cleaning directory of lecture 01 *****)
	@cd lectures/01_intro && make clean

.PHONY: L01 C01

