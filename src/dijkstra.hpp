#pragma once

#include <iostream>

#include "../inc/graph.h"
#include "timer.hpp"

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

void printPath(int parent[], int j)
{


    if (parent[j] == - 1) // IF ITS IS SOURCE
        return;

    printPath(parent, parent[j]);

    std::cout<<j<<" ";
}

void print_utility(Graph graph, int *dist,int * path)
{
    for (int i=0;i<graph.size();i++)
    {
        std::cout<<"Shortest distance from 0 to: "<<i<<" is"<<dist[i]<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

    for (int i=0;i<graph.size();i++)
    {
        if(dist[i]==9999)
        {
        std::cout<<"Path distance from 0 to: "<<i<<"    No connection!";
        std::cout<<std::endl;
        }else
        {
        std::cout<<"Path distance from 0 to: "<<i<<"    0 ";
        printPath(path,i);
        std::cout<<std::endl;
        }
    }

}


void dijkstra(Graph graph,int start_point)
{

    int distance[graph.size()];
    bool is_shortest_way[graph.size()];
    int path[graph.size()];

    for(int i=0;i<graph.size();i++)
    {
        path[0]=-1;
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
                path[v] = u;
            }
        }
    }

      //  std::cout<<std::endl;        std::cout<<std::endl;

   print_utility(graph,distance,path);


}


