#include <iostream>

#include "../inc/graph.h"
#include "dijkstra.hpp"


int main()
{
    Graph graph;
    //graph.fill_test_array(graph);
    graph.fill_graph_with_random(graph,100,50);
    dijkstra(graph,0);

    return 0;
}
