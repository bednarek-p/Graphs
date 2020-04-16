#pragma once

#include <iostream>
#include <fstream>
#include <string>


#include "Matrix_graph.h"
#include "list_graph.h"
void print_data_to_file(std::string file_name, std::string text);
void append_data_to_file(std::string file_name, std::string text);
void read_Matrix_graph_data_from_file(std::string file_name,Matrix_graph & Matrix_graph);
void read_list_graph_data_from_file(std::string file_name,List_graph & graph);
