#include <iostream>
#include <string>

#include "../inc/graph.h"
#include "../inc/timer.h"
#include "../inc/file_staff.h"
#define INT_MAX 9999




int minimal_distance(const Graph &graph,int *distance, bool *is_shortest_way);
void printPath(int parent[], int j);
void dijkstra(const Graph & graph,int start_point,int test_number);


void print_utility(const Graph &graph,int *dist,int * path);


void path_to_string(int *parent,int j,std::string &name);
std::string data_to_string(const Graph &graph, int *dist, int *path);
