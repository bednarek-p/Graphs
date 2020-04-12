#include "../inc/tests.h"

void test_dijkstra_for_matrix()
{
int * tab = new int [5];
tab[0]=10;
tab[1]=50;
tab[2]=100;
tab[3]=500;
tab[4]=1000;


for(int i=0;i<=4;i++)
{
        for(int density =25;density<=100;density+=25)
        {
            for( int test_numbers=0;test_numbers<100;test_numbers++)
            {
            Graph graph;
            print_data_to_file("MATRIX/"+std::to_string(density)+"/graph_data_"+std::to_string(tab[i])+"_"+std::to_string(test_numbers)+".txt",graph.generate_random_graph_data(tab[i],density,0));
            read_graph_data_from_file("MATRIX/"+std::to_string(density)+"/graph_data_"+std::to_string(tab[i])+"_"+std::to_string(test_numbers)+".txt",graph);
            dijkstra(graph,0,test_numbers,density,tab[i]);
            }
        }
}


delete [] tab;

}

void test_dijkstra_for_list()
{


int * tab = new int [5];
tab[0]=10;
tab[1]=50;
tab[2]=100;
tab[3]=500;
tab[4]=1000;


for(int i=0;i<=4;i++)
{
        for(int density =25;density<=100;density+=25)
        {
            for( int test_numbers=0;test_numbers<100;test_numbers++)
            {
            List_graph list_g;
            print_data_to_file("LIST/"+std::to_string(density)+"/graph_data_"+std::to_string(tab[i])+"_"+std::to_string(test_numbers)+".txt",list_g.generate_random_graph_data(tab[i],density,0));
            read_graph_list_data_from_file("LIST/"+std::to_string(density)+"/graph_data_"+std::to_string(tab[i])+"_"+std::to_string(test_numbers)+".txt",list_g);
            dijkstra_for_list(list_g,0,test_numbers,density,tab[i]);
            }
        }
}
delete [] tab;
}
