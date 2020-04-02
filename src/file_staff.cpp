#include "../inc/file_staff.h"

void print_data_to_file(std::string file_name, std::string text)
{
  std::ofstream file (file_name, std::ofstream::out);
  file << text;
  file.close();
  return ;
}
