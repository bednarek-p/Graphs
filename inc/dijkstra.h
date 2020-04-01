#include <iostream>

#include "../inc/graph.h"
#include "../inc/timer.h"

#define INT_MAX 9999




int minimal_distance(const Graph &graph,int *distance, bool *is_shortest_way);
void printPath(int parent[], int j);
void print_utility(const Graph &graph,int *dist,int * path);
void dijkstra(const Graph & graph,int start_point);

