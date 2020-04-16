#include "../inc/file_staff.h"

void print_data_to_file(std::string file_name, std::string text)
{
  std::ofstream file ("./data/"+file_name, std::ofstream::out);
  file << text;
  file.close();
  return ;
}

void read_Matrix_graph_data_from_file(std::string file_name,Matrix_graph & Matrix_graph)
{
    std::ifstream file;
    file.open ("./data/"+file_name);
    if (!file.is_open()) return;
    std::string word;
    int counter=0;
    int connections_number=0;
    int vertices =0;
    int * source_vertex =nullptr;
    int * target_vertex =nullptr;
    int * weight =nullptr;
    int array_counter =-1;
    while (file >> word)
    {
        if(counter==0)
        {
            connections_number=std::stoi(word);
            source_vertex = new int [connections_number];
            target_vertex = new int [connections_number];
            weight = new int [connections_number];
        }

        if(counter==1)
        {
            vertices=std::stoi(word);
        }


        if(counter>2)
        {
            if(counter%3==0)
            {
                array_counter++;
                source_vertex[array_counter]=std::stoi(word);
            }
            if(counter%3==1)
            {
                target_vertex[array_counter]=std::stoi(word);
            }
            if(counter%3==2)
            {
                weight[array_counter]=std::stoi(word);
            }
        }
    counter++;
    }


    for(int i=0;i<vertices;i++)
    {
        Matrix_graph.add_vertex(i);
    }

       for (int i=0;i<connections_number;i++)
    {
    Matrix_graph.add_connection(source_vertex[i],target_vertex[i],weight[i]);
    }


delete [] source_vertex;
delete [] target_vertex;
delete [] weight;

}

void read_list_graph_data_from_file(std::string file_name,List_graph & graph)
{
    std::ifstream file;
    file.open ("./data/"+file_name);
    if (!file.is_open()) return;
    std::string word;
    int counter=0;
    int connections_number=0;
    int * source_vertex =nullptr;
    int * target_vertex =nullptr;
    int * weight =nullptr;
    int array_counter =-1;
    while (file >> word)
    {
        if(counter==0)
        {
            connections_number=std::stoi(word);
            source_vertex = new int [connections_number];
            target_vertex = new int [connections_number];
            weight = new int [connections_number];
        }

        if(counter>2)
        {
            if(counter%3==0)
            {
                array_counter++;
                source_vertex[array_counter]=std::stoi(word);
            }
            if(counter%3==1)
            {
                target_vertex[array_counter]=std::stoi(word);
            }
            if(counter%3==2)
            {
                weight[array_counter]=std::stoi(word);
            }
        }
    counter++;
    }


    for (int i=0;i<connections_number;i++)
    {
    graph.add_connection(source_vertex[i],target_vertex[i],weight[i]);
    }


delete [] source_vertex;
delete [] target_vertex;
delete [] weight;

}


void append_data_to_file(std::string file_name, std::string text)
{
  std::ofstream file ("./data/"+file_name, std::ofstream::app);
  file << text;
  file.close();
}
