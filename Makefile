all: exe clean

exe: main.o Matrix_graph.o dijkstra.o file_staff.o tests.o list_graph.o dijkstra_list.o
	g++  main.o Matrix_graph.o dijkstra.o file_staff.o tests.o list_graph.o dijkstra_list.o  -o exe

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

dijkstra.o: ./src/dijkstra.cpp
	g++ -c ./src/dijkstra.cpp

Matrix_graph.o: ./src/Matrix_graph.cpp
	g++ -c ./src/Matrix_graph.cpp

file_staff.o: ./src/file_staff.cpp
	g++ -c ./src/file_staff.cpp

tests.o: ./src/tests.cpp
	g++ -c ./src/tests.cpp

list_graph.o: ./src/list_graph.cpp
	g++ -c ./src/list_graph.cpp

dijkstra_list.o: ./src/dijkstra_list.cpp
	g++ -c ./src/dijkstra_list.cpp

clean:
	rm -f *.o *~ 
	rm -f ./data/*.txt
	rm -f ./data/MATRIX/25/*.txt
	rm -f ./data/MATRIX/50/*.txt
	rm -f ./data/MATRIX/75/*.txt
	rm -f ./data/MATRIX/100/*.txt
	rm -f ./data/LIST/25/*.txt
	rm -f ./data/LIST/50/*.txt
	rm -f ./data/LIST/75/*.txt
	rm -f ./data/LIST/100/*.txt
	mkdir -p ./data/MATRIX/25 ./data/MATRIX/50 ./data/MATRIX/75 ./data/MATRIX/100
	mkdir -p ./data/LIST/25 ./data/LIST/50 ./data/LIST/75 ./data/LIST/100
