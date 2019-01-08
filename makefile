Rock: main.o head.o
	g++ -o Rock main.o head.o

main.o: main.cpp head.o
	g++ -c main.cpp

head.o: head.cpp head.h
	g++ -c head.cpp