all: exe clean

exe: main.o graph.o dijkstra.o 
	g++  main.o graph.o dijkstra.o  -o exe

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

dijkstra.o: ./src/dijkstra.cpp
	g++ -c ./src/dijkstra.cpp

graph.o: ./src/graph.cpp
	g++ -c ./src/graph.cpp


clean:
	rm -f *.o *~ 