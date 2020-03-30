#include "../inc/graph.h"

#include <assert.h>
Graph::Graph()
{

}
Graph::~Graph()
{

}

void Graph::add_vertex(const int& value)
{
    assert(size()<MAX_SIZE);

    labels[number_of_vertices]=value;
    int new_vertex_number=number_of_vertices;
    number_of_vertices++;

    for(int i=0; i<number_of_vertices;i++)
    {
        path_array[i][new_vertex_number]=0;
        path_array[new_vertex_number][i]=0;
    }
}

void Graph::add_connection(int source,int target,int weight)
{
assert(source<size() && target<size());
path_array[source][target]=weight;
}

bool Graph::is_connection(int source,int target)
{
    assert(source<size() && target<size());
    bool tmp_is_connection = false;
    if (path_array[source][target]>0)
        tmp_is_connection= true;
    return tmp_is_connection;
}

int Graph::connection_weight(int source,int target)
{
    assert(source<size() && target<size());
    return path_array[source][target];
}

int& Graph::operator [] (int value)
{
assert(value<size());
return labels[value];
}

int Graph::operator [] (int value) const
{
assert(value<size());
return labels[value];
}


int Graph::size() const
{
    return number_of_vertices;
}
