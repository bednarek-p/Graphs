#include <iostream>
#include <time.h>
#include "../inc/graph.h"
#include "../inc/dijkstra.h"
#include "../inc/tests.h"
#include "../inc/file_staff.h"
#include "../inc/list_graph.h"

int main()
{

    srand(time(NULL));
    //test_dijkstra_for_matrix();
    List_graph list_g;
    list_g.add_connection(0,1,10);
    list_g.add_connection(1,2,12);
    list_g.add_connection(0,3,13);
    list_g.add_connection(2,4,14);
    list_g.add_connection(0,5,15);

    for(int i=0;i<5;i++)
    {
    std::cout<<i<<"->";
    list_g.print_graph_list_data(list_g.head[i]);
    std::cout<<std::endl;
    }
    return 0;

}


