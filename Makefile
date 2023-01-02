all: compile link 

compile:
	g++ -Isfml/include -c src/main.cpp src/app.cpp

link:
	g++ main.o app.o -o app