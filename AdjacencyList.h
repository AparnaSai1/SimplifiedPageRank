//submitting my own code from last semester again (asked for permission beforehand)

#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;

// used the template for this to declare all of my variables and methods


class AdjacencyList
{
private:
    map<int, double> powerIterations; // stores the power iterations for each page
    map<int, vector<pair<int, double>>> adjacencyGraph; // adjacency list rep of the graph
    map<string, int> adjacentPages2; // keeps track of how many links point to a page
    map<string, int> adjacentPages; // maps page urls to their ids
    int rankValue{1}; // used to assign unique ids to new pages

public:
    void computePageRank(int power_iterations); // calculates the page rank
    string printRank(); // prints the rank of each page
    void updateEdgeWeights(); // updates the weights of edges in the graph
    string findPageUrlID(int webpage_number); // finds the url of a page given its id
    int addUpdateWebpage(const string& the_url, bool isit); // adds or updates a webpage in the graph
    int addEdges(const string& from, const string& to); // adds an edge between two pages
    map<int, string> idToUrl; // maps page ids back to their urls

};
 main.cpp
 Download

//submitting my own code from last semester again (asked for permission beforehand)

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
