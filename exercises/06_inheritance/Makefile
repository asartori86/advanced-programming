SRC = $(wildcard *.cc)
CXXFLAGS = -std=c++14 -Wall -Wextra -I ../../lectures/04_error_handling -O0
EXE = $(SRC:.cc=.x)
INC = $(wildcard *.h)
CXX=c++

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


