#pragma once

#include <iostream>
#include <fstream>
#include <string>


#include "graph.h"
void print_data_to_file(std::string file_name, std::string text);
void append_data_to_file(std::string file_name, std::string text);
void read_graph_data_from_file(std::string file_name,Graph & graph);
