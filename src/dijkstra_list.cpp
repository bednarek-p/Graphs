#include "../inc/dijkstra_list.h"

void dijkstra_for_list(const List_graph & list_graph,int start_value)
{

    Node* array[5];
    for(int i=0;i<5;i++)
    {
        array[i]=list_graph.head[i];
    }
    for(int i=0;i<5;i++)
    {
        std::cout<<array[i]->value<<" ";
    }



        //

}
