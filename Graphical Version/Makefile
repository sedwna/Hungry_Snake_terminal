all: compile link 

compile:
	g++ -Isfml/include -c src/*.cpp  

link:
	g++ *.o  -o  app -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio