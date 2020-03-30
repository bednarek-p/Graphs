#pragma once


class Graph
{
    static const int  MAX_SIZE =5;
    int path_array [MAX_SIZE] [MAX_SIZE];
    int labels[MAX_SIZE];
    int number_of_vertices;
public:

    Graph();
    ~Graph();



    void add_vertex(const int& value);
    void add_connection(int source, int target,int weight);
    void delete_connection(int source,int target);
    int& operator [] (int value);
    int operator [] (int value) const;
    int size() const;
    bool is_connection (int source, int target);
    int connection_weight (int source,int target);
    //std::set<int> neighbors (int vertex) const;
};
