all : bin/main.exe bin/test.exe
	@echo DONE.

RunMain : bin/main.exe
	@./bin/main.exe

RunTest : bin/test.exe
	@./bin/test.exe
main : bin/main.exe
	@echo DONE.

test : bin/test.exe
	@echo DONE.

bin/main.exe : bin/main.o
	@echo Make bin/main.exe
	@g++  bin/main.o  -o bin/main.exe

bin/main.o : src/main.cpp
	@echo Make bin/main.o
	@g++ -c -I incl src/main.cpp  -o bin/main.o

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
