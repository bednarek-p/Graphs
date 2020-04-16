#include "../inc/Matrix_graph.h"
Matrix_graph::Matrix_graph()
{
    path_array = new int*[MAX_SIZE];

    for(int i = 0; i < MAX_SIZE; ++i)
    {
        path_array[i] = new int[MAX_SIZE];
    }
}

Matrix_graph::~Matrix_graph()
{
    for(int i=0; i<MAX_SIZE; i++)
     delete[] path_array[i];

   delete[] path_array;
}

void Matrix_graph::add_vertex(const int& value)
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

void Matrix_graph::add_connection(int source,int target,int weight)
{
assert(source<size() && target<size());
path_array[source][target]=weight;
}

bool Matrix_graph::is_connection(int source,int target)
{
    assert(source<size() && target<size());
    bool tmp_is_connection = false;

    if (path_array[source][target]>0)
        tmp_is_connection= true;

    return tmp_is_connection;
}

int Matrix_graph::connection_weight(int source,int target)
{
    assert(source<size() && target<size());
    return path_array[source][target];
}

int& Matrix_graph::operator [] (int value)
{
    assert(value<size());
    return labels[value];
}

int Matrix_graph::operator [] (int value) const
{
    assert(value<size());
    return labels[value];
}


int Matrix_graph::get_value(int i, int j) const
{
    return path_array[i][j];
}

void Matrix_graph::fill_Matrix_graph_with_random( Matrix_graph & Matrix_graph,const int number_of_vertices, const int Matrix_graph_density)
{
    for(int i=0;i<number_of_vertices;i++)
    {
        Matrix_graph.add_vertex(i);
    }



    int edge = (Matrix_graph_density*number_of_vertices*(number_of_vertices-1))/200;
    std::cout<<edge<<std::endl;



int random_source=0;
int random_target=0;
int random_weight=0;
    for (int i=0;i<edge;i++)
    {
        random_weight = std::rand() % 1000 + 1;
        do
        {
            random_source=rand() % number_of_vertices + 0;
            random_target=rand() % number_of_vertices + 0;
        } while( random_target==random_source );
        Matrix_graph.add_connection(random_source,random_target,random_weight);
    }


}

std::string Matrix_graph::generate_random_Matrix_graph_data(const int number_of_vertices, const int Matrix_graph_density,const int start_vertex)
{
    std::string data="";
    int edge = (Matrix_graph_density*number_of_vertices*(number_of_vertices-1))/200;
    data+=std::to_string(edge)+" "+std::to_string(number_of_vertices)+" "+std::to_string(start_vertex)+"\n";



    int random_source=0;
    int random_target=0;
    int random_weight=0;

    for (int i=0;i<edge;i++)
    {
        random_weight = std::rand() % 1000 + 1;
        do
        {
            random_source=rand() % number_of_vertices + 0;
            random_target=rand() % number_of_vertices + 0;
        } while( random_target==random_source );
        data+=std::to_string(random_source)+" "+std::to_string(random_target)+" "+std::to_string(random_weight)+"\n";
    }



    return data;
}


int Matrix_graph::size()const
{
    return number_of_vertices;
}
