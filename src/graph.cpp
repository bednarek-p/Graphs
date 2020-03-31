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
int Graph::get_value(int i, int j)
{
    return path_array[i][j];
}
/*
int Graph::get_main_array(Graph graph)
{
    return graph.path_array;
}
*/
void Graph::fill_test_array(Graph &graph)
{
    graph.add_vertex(0);
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);
    graph.add_vertex(6);
    graph.add_vertex(7);
    graph.add_vertex(8);

    graph.add_connection(0, 1, 4);
    graph.add_connection(0, 7, 8);
    graph.add_connection(1, 2, 8);
    graph.add_connection(1, 7, 11);
    graph.add_connection(2, 3, 7);
    graph.add_connection(2, 8, 2);
    graph.add_connection(2, 5, 4);
    graph.add_connection(3, 4, 9);
    graph.add_connection(3, 5, 14);
    graph.add_connection(4, 5, 10);
    graph.add_connection(5, 6, 2);
    graph.add_connection(6, 7, 1);
    graph.add_connection(6, 8, 6);
    graph.add_connection(7, 8, 7);

}

int Graph::size() const
{
    return number_of_vertices;
}
