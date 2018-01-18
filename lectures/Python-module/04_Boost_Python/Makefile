include ./Makefile.ini # PYTHON e BOOST vars
SRC = $(wildcard *.cc)
SO = $(SRC:.cc=.so)
CXX = g++
LFLAGS = -L$(BOOST_PYTHON) $(BOOST_PYTHON_LIB)
CXXFLAGS =  -std=c++11 -Wall -Wextra 

all: $(SO)

%.so: %.o 
	$(CXX) -shared $< $(LFLAGS) -o $@

%.o: %.cc 
	$(CXX)  $(CXXFLAGS) -I$(PYTHON) -fPIC -c $<

clean:
	rm -f $(SO) *~

.PHONY: clean

