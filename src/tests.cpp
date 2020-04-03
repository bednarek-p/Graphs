#include "../inc/tests.h"

void test()
{


    for( int test_numbers=0;test_numbers<100;test_numbers++)
    {
    Graph graph;
    print_data_to_file("./data/graph_data_"+std::to_string(test_numbers)+".txt",graph.generate_random_graph_data(1000,100,0));
    read_graph_data_from_file("graph_data_"+std::to_string(test_numbers)+".txt",graph);
    dijkstra(graph,0,test_numbers);
    }


}
