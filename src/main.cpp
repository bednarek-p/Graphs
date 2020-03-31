#include <iostream>

#include "../inc/graph.h"
#include "dijkstra.hpp"


int main()
{
    Graph graph;
    graph.fill_test_array(graph);
    dijkstra(graph,0);

    return 0;
}
