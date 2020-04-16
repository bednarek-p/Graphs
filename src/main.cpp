#include <iostream>
#include <time.h>
#include <typeinfo>

#include "../inc/Matrix_graph.h"
#include "../inc/dijkstra.h"
#include "../inc/tests.h"
#include "../inc/file_staff.h"
#include "../inc/dijkstra_list.h"


int main()
{

    srand(time(NULL));
    test_dijkstra_for_matrix();
    test_dijkstra_for_list();

    return 0;

}


