EXE = ap
GDIR=../01_greetings_library

LFLAGS = -lgreetings -L $(GDIR) -Wl,-rpath,$(GDIR)
CXX = g++
CFLAGS = -I include -g -I $(GDIR)/include

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CFLAGS)


$(EXE): main.o src/date.o src/student.o
	$(CXX) $^ -o $(EXE) $(LFLAGS)

main.o: main.cc
main.o: src/student.o src/date.o

src/date.o: include/date.h

src/student.o: include/student.h

clean:
	rm -rf src/*.o main.o $(EXE) **/*~ *~

.PHONY: clean 


