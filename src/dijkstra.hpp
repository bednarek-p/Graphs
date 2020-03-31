#include <iostream>

#include "../inc/graph.h"

#define INT_MAX 9999


int minimal_distance(Graph graph,int *distance, bool *is_shortest_way)
{
    int minimum = INT_MAX;
    int minimum_index;

    for(int i=0;i<graph.size();i++)
    {
        if(is_shortest_way[i] == false && distance[i] <= minimum)
        {
            minimum=distance[i];
            minimum_index=i;
        }
    }

return minimum_index;
}




void dijkstra(Graph graph,int start_point)
{
    int distance[graph.size()];
    bool is_shortest_way[graph.size()];

    for(int i=0;i<graph.size();i++)
    {
        distance[i]=INT_MAX;
        is_shortest_way[i]=false;
    }
    distance[start_point]=0;


    for(int i=0;i<graph.size()-1;i++)
    {
        int u = minimal_distance(graph,distance,is_shortest_way);
        is_shortest_way[u] =true;
        for(int v=0; v<graph.size();v++)
        {
            if(!is_shortest_way[v] && graph.get_value(u,v) && distance[u]!= INT_MAX && distance[u]+graph.get_value(u,v)<distance[v])
            {
                distance[v]=distance[u]+graph.get_value(u,v);
            }
        }
    }



    for (int i=0;i<graph.size();i++)
    {
        std::cout<<"Shortest distance from 0 to: "<<i<<" is"<<distance[i]<<std::endl;
    }


}


