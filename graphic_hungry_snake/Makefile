all: compile link 

compile:
	g++ -Isfml/include -c src/main.cpp  src/app.cpp src/game.cpp src/frog.cpp src/snake.cpp

link:
	g++ main.o app.o game.o frog.o snake.o -o  app -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system