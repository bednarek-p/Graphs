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
}

void List_graph::add_connection(int source, int target, int weight)
{
        Node* newNode = get_adj_list_node(target, head[source],weight);
        head[source] = newNode;
        Node_number++;
}

void List_graph::print_Matrix_graph_list_data(Node * ptr)
{
    while(ptr!=nullptr)
    {
        std::cout<<"->"<<ptr->value<<" ";
        ptr=ptr->next;
    }
    std::cout<<std::endl;
}

int List_graph::size() const
{
    return Node_number;
}


std::string List_graph::generate_random_Matrix_graph_data(const int number_of_vertices, const int Matrix_graph_density,const int start_vertex)
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
        add_connection(random_source,random_target,random_weight);
    }



    return data;
}





