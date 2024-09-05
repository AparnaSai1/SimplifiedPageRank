
#include "AdjacencyList.h"
#include <string>
#include <iostream>
using namespace std;

//i took this straight from the template, and added my code where it said to input stuff
//main method

int main()
{
    string from;
    string to;
    int line_number;
    int power_iterations;
    cin >> line_number >> power_iterations;

    AdjacencyList the_graph;

    int i = 0;
    while (i < line_number)
    {
        cin >> from >> to;
        the_graph.addEdges(from, to);
        i++;
    }

    the_graph.computePageRank(power_iterations);

    return 0;
}
