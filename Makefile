all: program

program: main.o menu.o tablica.o
	g++ main.o menu.o tablica.o tablica_wysw.o -o program

main.o: main.cpp
	g++ -c -Wall main.cpp

menu.o: menu.cpp
	g++ -c -Wall menu.cpp

tablica.o: tablica.cpp
	g++ -c -Wall tablica.cpp

tablica_wysw.o: tablica_wysw.cpp
	g++ -c -Wall tablica_wysw.cpp

clean:
	rm -rf *o program
