#include <iostream>
#include <time.h>
#include <typeinfo>

#include "../inc/graph.h"
#include "../inc/dijkstra.h"
#include "../inc/tests.h"
#include "../inc/file_staff.h"
//#include "../inc/list_graph.h"
#include "../inc/dijkstra_list.h"

struct Minimal_heap_node
{
    int  v;
    int distance;
};

// Structure to represent a min heap
struct Minimal_heap
{
    int size;
    int capacity;
    int *pos;
    struct Minimal_heap_node **arr;
};


struct Minimal_heap_node* new_minimal_heap_node(int v, int distance)
{
    struct Minimal_heap_node* Minimal_heap_node =
           (struct Minimal_heap_node*) malloc(sizeof(struct Minimal_heap_node));
    Minimal_heap_node->v = v;
    Minimal_heap_node->distance = distance;
    return Minimal_heap_node;
}

// to create a Min Heap
struct Minimal_heap* create_minimal_heap(int capacity)
{
    struct Minimal_heap* Minimal_heap =
         (struct Minimal_heap*) malloc(sizeof(struct Minimal_heap));
    Minimal_heap->pos = (int *)malloc(capacity * sizeof(int));
    Minimal_heap->size = 0;
    Minimal_heap->capacity = capacity;
    Minimal_heap->arr =
         (struct Minimal_heap_node**) malloc(capacity * sizeof(struct Minimal_heap_node*));
    return Minimal_heap;
}

//swap two nodes of min heap
void swap_minimal_heap_node(struct Minimal_heap_node** a, struct Minimal_heap_node** b)
{
    struct Minimal_heap_node* tmp = *a;
    *a = *b;
    *b = tmp;
}

// A standard function to heapify at given index
// This function also updates position of nodes when they are swapped.
// Position is needed for decrease_key()
void min_heapify(struct Minimal_heap* Minimal_heap, int index)
{
    int smallest, left, right;
    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < Minimal_heap->size &&
        Minimal_heap->arr[left]->distance < Minimal_heap->arr[smallest]->distance )
      smallest = left;

    if (right < Minimal_heap->size &&
        Minimal_heap->arr[right]->distance < Minimal_heap->arr[smallest]->distance )
      smallest = right;

    if (smallest != index)
    {
        // The nodes to be swapped in min heap
        Minimal_heap_node *smallest_node = Minimal_heap->arr[smallest];
        Minimal_heap_node *index_node = Minimal_heap->arr[index];

        // Swap positions
        Minimal_heap->pos[smallest_node->v] = index;
        Minimal_heap->pos[index_node->v] = smallest;

        // Swap nodes
        swap_minimal_heap_node(&Minimal_heap->arr[smallest], &Minimal_heap->arr[index]);

        min_heapify(Minimal_heap, smallest);
    }
}

// A utility function to check if the given Minimal_heap is ampty or not
int is_empty(struct Minimal_heap* Minimal_heap)
{
    return Minimal_heap->size == 0;
}

// Standard function to extract minimum node from heap
struct Minimal_heap_node* extractMin(struct Minimal_heap* Minimal_heap)
{
    if (is_empty(Minimal_heap))
        return NULL;

    // Store the root node
    struct Minimal_heap_node* root = Minimal_heap->arr[0];

    // Replace root node with last node
    struct Minimal_heap_node* lastNode = Minimal_heap->arr[Minimal_heap->size - 1];
    Minimal_heap->arr[0] = lastNode;

    // Update position of last node
    Minimal_heap->pos[root->v] = Minimal_heap->size-1;
    Minimal_heap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --Minimal_heap->size;
    min_heapify(Minimal_heap, 0);

    return root;
}


void decrease_key(struct Minimal_heap* Minimal_heap, int v, int distance)
{
    // Get the index of v in  heap array
    int i = Minimal_heap->pos[v];
    // Get the node and update its distance value
    Minimal_heap->arr[i]->distance = distance;

    while (i && Minimal_heap->arr[i]->distance < Minimal_heap->arr[(i - 1) / 2]->distance)
    {
        // Swap this node with its parent
        Minimal_heap->pos[Minimal_heap->arr[i]->v] = (i-1)/2;
        Minimal_heap->pos[Minimal_heap->arr[(i-1)/2]->v] = i;
        swap_minimal_heap_node(&Minimal_heap->arr[i],  &Minimal_heap->arr[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}


bool is_in_minimal_heap(struct Minimal_heap *Minimal_heap, int v)
{
   if (Minimal_heap->pos[v] < Minimal_heap->size)
     return true;
   return false;
}


void printArr(int distance[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}


void dijkstra_test( List_graph graph, int source,int V)
{
    int path_data[V];
    int distance[V];

    struct Minimal_heap* Minimal_heap = create_minimal_heap(V);


    for (int v = 0; v < V; ++v)
    {
        distance[v] = 1000;
        Minimal_heap->arr[v] = new_minimal_heap_node(v, distance[v]);
        Minimal_heap->pos[v] = v;
    }

    // Make distance value of source vertex as 0 so that it is extracted first
    Minimal_heap->arr[source] = new_minimal_heap_node(source, distance[source]);
    Minimal_heap->pos[source]   = source;
    distance[source] = 0;
    decrease_key(Minimal_heap, source, distance[source]);

    // Initially size of min heap is equal to V
    Minimal_heap->size = V;

    while (!is_empty(Minimal_heap))
    {

        struct Minimal_heap_node* Minimal_heap_node = extractMin(Minimal_heap);
        int u = Minimal_heap_node->v; // Store the extracted vertex number

        struct Node* pCrawl = graph.head[u];
        while (pCrawl != NULL)
        {
            int v = pCrawl->value;

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (is_in_minimal_heap(Minimal_heap, v) && distance[u] != 1000 &&
                                          pCrawl->weight + distance[u] < distance[v])
            {
                distance[v] = distance[u] + pCrawl->weight;
                // update distance value in min heap also
                decrease_key(Minimal_heap, v, distance[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printArr(distance, V);
}



int main()
{

    srand(time(NULL));
    //test_dijkstra_for_matrix();
    List_graph list_g;

    list_g.add_connection(0,1,4);
    list_g.add_connection(1,2,8);
    list_g.add_connection(2,3,7);
    list_g.add_connection(3,4,9);
    list_g.add_connection(4,5,10);
    list_g.add_connection(2,5,4);
    list_g.add_connection(5,6,2);
    list_g.add_connection(6,8,6);
    list_g.add_connection(6,7,1);
    list_g.add_connection(0,7,8);
    list_g.add_connection(7,8,7);
    list_g.add_connection(2,8,2);
    list_g.add_connection(1,7,11);
    list_g.add_connection(3,5,14);

    /*
    //std::cout<<list_g.size();
   // std::cout<<typeid(list_g).name()<<std::endl;
    Node* array[8];
    for(int i=0;i<8;i++)
    {
        array[i]=list_g.head[i];
    }
    Node* ptr ;
    for(int i=0;i<list_g.size();i++)
    {
        ptr=array[i];
            while(ptr!=nullptr)
        {
            std::cout<<"->"<<ptr->value<<" ";
            ptr=ptr->next;
        }
        std::cout<<std::endl;
    }
*/

dijkstra_test(list_g,0,9);

   // dijkstra_for_list(list_g,0);
    return 0;

}


