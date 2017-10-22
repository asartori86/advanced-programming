SRC = $(wildcard *.cc)
CXX = c++
CXXFLAGS = -g -std=c++11 -Wall -Wextra
EXE = $(SRC:.cc=.x)
INC = $(wildcard *.h)

.SUFFIXES:
.SUFFIXES: .cc .x

all: $(EXE)

%.x: %.cc 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC) $(INC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -f $(EXE) *~

.PHONY: clean

03_error.x: ap_error.h
04_assert.x: ap_error.h
05_date.x: ap_error.h
06_ctor.x: ap_error.h


