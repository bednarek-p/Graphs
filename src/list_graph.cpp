#include "../inc/list_graph.h"

Node*  List_graph::get_adj_list_node(int dest,Node * head,int weight)
{
    Node * new_node = new Node;
    new_node->value=dest;
    new_node->weight=weight;
    new_node->next = head;

    return new_node;
}


List_graph::List_graph()
{
    head = new Node *[MAX_SIZE]();
    for(int i =0; i<MAX_SIZE;i++)
    {
        head[i]=nullptr;
    }
}

List_graph::~List_graph()
{

    for(int i =0; i<MAX_SIZE;i++)
    {
      delete [] head[i];
    }
    delete [] head;
}

void List_graph::add_connection(int source, int target, int weight)
{
        Node* newNode = get_adj_list_node(target, head[source],weight);
        head[source] = newNode;
}

void List_graph::print_graph_list_data(Node * ptr)
{
    while(ptr!=nullptr)
    {
        std::cout<<"->"<<ptr->value<<" ";
        ptr=ptr->next;
    }
    std::cout<<std::endl;
}
