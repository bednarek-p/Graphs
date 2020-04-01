#include <iostream>

#include "../inc/graph.h"
#include "../inc/dijkstra.h"


int main()
{
    Graph graph;


    graph.fill_graph_with_random(graph,1000,100);
    dijkstra(graph,0);

    return 0;
}
