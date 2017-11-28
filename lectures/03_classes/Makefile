SRC = $(wildcard *.cc)
CXX = c++
CXXFLAGS = -g -std=c++11
EXE = $(SRC:.cc=.x)

.SUFFIXES:
.SUFFIXES: .cc .x

all: $(EXE)

%.x: %.cc
	$(CXX) $< -o $@ $(CXXFLAGS)

08_template_class_c++14.x: 08_template_class_c++14.cc
	$(CXX) $< -o $@ -g --std=c++14

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -f $(EXE) *~

.PHONY: clean

pointers.x: pointers.cc
	$(CXX) $< -o $@ -std=c++11
