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
    Node* get_adj_list_node(int dest,Node * head,int weight);
    int Node_number=0;
public:

    Node** head;

    List_graph();
    ~List_graph();
    void add_connection(int source, int target, int weight);
    void print_graph_list_data(Node * ptr);
    int size() const;
};
