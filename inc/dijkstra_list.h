#pragma once

#define INT_MAX_LIST 9999

#include <iostream>

#include "list_graph.h"
#include "timer.h"
#include "file_staff.h"


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


struct Minimal_heap_node* extractMin(struct Minimal_heap* Minimal_heap);
struct Minimal_heap* create_minimal_heap(int capacity);
struct Minimal_heap_node* new_minimal_heap_node(int v, int distance);

void dijkstra_for_list (List_graph graph, int source,int test_number,int density,int V);
bool is_in_minimal_heap(struct Minimal_heap *Minimal_heap, int v);
void decrease_key(struct Minimal_heap* Minimal_heap, int v, int distance);
int  is_empty(struct Minimal_heap* Minimal_heap);
void min_heapify(struct Minimal_heap* Minimal_heap, int index);
void swap_minimal_heap_node(struct Minimal_heap_node** a, struct Minimal_heap_node** b);

void print_path_list(int parent[], int j);
void print_utility_list(int dist[], int n,  int parent[]);
void path_to_string_list(int*parent, int j,std::string & name);
std::string data_to_string_list(const List_graph &graph, int *dist, int *path,int number_of_vertices);

