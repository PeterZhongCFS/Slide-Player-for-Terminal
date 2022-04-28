all : bin/test.exe
	@echo DONE.

bin/test.exe : bin/test.o
	@echo Make bin/test.exe
	@g++  bin/test.o  -o bin/test.exe

bin/test.o : src/test.cpp
	@echo Make bin/test.o
	@g++ -c -I incl src/test.cpp  -o bin/test.o

.PHONY : clean # Windows
clean:
	del bin\* /q

.PHONY : clear # Linux
clear:
	rm bin/*
