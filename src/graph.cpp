#include "../inc/graph.h"
Graph::Graph()
{
    path_array = new int*[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; ++i)
    {
        path_array[i] = new int[MAX_SIZE];
    }
}

Graph::~Graph()
{
    for(auto i=0; i<MAX_SIZE; i++)
     delete[] path_array[i];

   delete[] path_array;
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
int Graph::get_value(int i, int j) const
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
    graph.add_vertex(9);
    //graph.add_vertex(10);

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

    graph.add_connection(8, 9, 10);
}


void Graph::fill_graph_with_random( Graph & graph,const int number_of_vertices, const int graph_density)
{
    for(int i=0;i<number_of_vertices;i++)
    {
        graph.add_vertex(i);
    }
    srand (time(NULL));


    int edge = (graph_density*number_of_vertices*(number_of_vertices-1))/200;
std::cout<<edge<<std::endl;



int random_source;
int random_target;
int random_weight;
    for (int i=0;i<edge;i++)
    {
        random_weight = rand() % 100 + 1;
        do
        {
            random_source=rand() % number_of_vertices;
            random_target=rand() % number_of_vertices;
        } while( random_target==random_source );
        //std::cout<<"weight: "<<random_weight<<"source: "<<random_source<<"target: "<<random_target<<std::endl;
        graph.add_connection(random_source,random_target,random_weight);
    }


}

int Graph::size()const
{
    return number_of_vertices;
}
