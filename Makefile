project1: fraction.o main.o point.o
	g++ -o project1 fraction.o main.o point.o

fraction.o: fraction.cc fraction.h
	g++ -c fraction.cc

main.o: main.cc fraction.h point.h
	g++ -c main.cc
	
point.o: point.cc fraction.h point.h
	g++ -c point.cc
