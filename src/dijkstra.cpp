//#pragma once


#include "../inc/dijkstra.h"

int minimal_distance(const Graph &graph,int *distance, bool *is_shortest_way)
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

void printPath(int *parent, int j)
{
    if (parent[j] == - 1) // IF ITS IS SOURCE
        return;

    printPath(parent, parent[j]);

    std::cout<<j<<" ";
}

void print_utility(const Graph &graph,int *dist,int * path)
{
    for (int i=0;i<graph.size();i++)
    {
        std::cout<<"Shortest distance from 0 to: "<<i<<" is:  "<<dist[i]<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

    for (int i=0;i<graph.size();i++)
    {
        if(dist[i]==INT_MAX)
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


void dijkstra(const Graph & graph,int start_point,int test_number)
{
    int* distance= new int [graph.size()];
    bool* is_shortest_way= new bool [graph.size()];
    int* path= new int[graph.size()];

    for(int i=0;i<graph.size();i++)
    {
        path[0]=-1;
        distance[i]=INT_MAX;
        is_shortest_way[i]=false;
    }
    distance[start_point]=0;

    Timer time;
    time.start();

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
    time.stop();
    time.print_time_duration();
    //print_utility(graph,distance,path);
    append_data_to_file("./data/all_timers.txt",std::to_string(time.return_time_duration())+"\n");
    print_data_to_file("./data/test_"+std::to_string(test_number)+".txt",data_to_string(graph,distance,path));
    //std::cout<<data_to_string(graph,distance,path);
    delete [] distance;
    delete [] is_shortest_way;
    delete [] path;
}

void path_to_string(int*parent, int j,std::string & name)
{

    if (parent[j] == - 1) // IF ITS IS SOURCE
        return ;

    path_to_string(parent, parent[j],name);
     name+=std::to_string(j)+" ";

}


std::string data_to_string(const Graph &graph, int *dist, int *path)
{
    std::string name="";
    std::string data_string="";
    for (int i=0;i<graph.size();i++)
    {
        data_string+="Shortest distance from 0 to: "+ std::to_string(i)+" is:  "+std::to_string(dist[i])+"\n";
    }


    for (int i=0;i<graph.size();i++)
    {
        if(dist[i]==INT_MAX)
        {
        data_string+="Path distance from 0 to: " + std::to_string(i) + "    No connection!\n";
        }else
        {
        data_string+="Path distance from 0 to: "+ std::to_string(i) +"    0 ";
        name="";
        path_to_string(path,i,name);
        data_string+=name;
        data_string+="\n";
        }
    }

    return data_string;
}


