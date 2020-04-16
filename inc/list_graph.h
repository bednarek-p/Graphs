#pragma once
#include <iostream>

struct Node{
int value;
int weight;
Node* next;
};




class List_graph
{
    static const int  MAX_SIZE =1000;
    int Node_number=0;

    Node* get_adj_list_node(int dest,Node * head,int weight);

public:

    Node** head;

    List_graph();
    ~List_graph();

    void add_connection(int source, int target, int weight);
    void print_Matrix_graph_list_data(Node * ptr);

    std::string generate_random_Matrix_graph_data(const int number_of_vertices, const int Matrix_graph_density,const int start_vertex);

    int size() const;
};
