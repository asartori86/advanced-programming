CXX=g++
LANG=ITALIANO

all: libgreetings.so

libgreetings.so: src/greetings.o src/conclusion.o
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -D$(LANG) -o $@ -c $< -Iinclude

src/greetings.o: include/greetings.h

src/conclusion.o: include/conclusion.h

clean:
	@rm -f *~ **/*~ libgreetings.so src/*.o

.PHONY: clean
