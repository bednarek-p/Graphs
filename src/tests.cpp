#include "../inc/tests.h"

void test()
{
    for( int test_numbers=0;test_numbers<100;test_numbers++)
    {
    srand(time(NULL));
    Graph graph;
    graph.fill_graph_with_random(graph,1000,100);
    dijkstra(graph,0,test_numbers);
    }

}
