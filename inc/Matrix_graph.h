#pragma once

#include <stdlib.h>
#include <iostream>
#include <assert.h>



class Matrix_graph
{
    static const int  MAX_SIZE =1000;
    int **path_array ;
    int labels[MAX_SIZE];
    int number_of_vertices=0;
public:

    Matrix_graph();
    ~Matrix_graph();



    void add_vertex(const int& value);
    void add_connection(int source, int target,int weight);
    void delete_connection(int source,int target);

    int& operator [] (int value);
    int operator [] (int value) const;

    int size() const;
    bool is_connection (int source, int target);
    int connection_weight (int source,int target);

    int get_value(int i,int j)const;
    void fill_Matrix_graph_with_random( Matrix_graph & Matrix_graph,const int number_of_vertices, const int Matrix_graph_density);

    std::string generate_random_Matrix_graph_data(const int number_of_vertices, const int Matrix_graph_density,const int start_vertex);
};
