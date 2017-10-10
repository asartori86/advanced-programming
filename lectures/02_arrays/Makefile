SRC = $(wildcard *.cc)
CXX = c++
CXXFLAGS = -g -std=c++11
EXE = $(SRC:.cc=.x)

.SUFFIXES:
.SUFFIXES: .cc .x

all: $(EXE)

%.x: %.cc
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -f $(EXE) *~

.PHONY: clean

pointers.x: pointers.cc
	$(CXX) $< -o $@ -std=c++11
