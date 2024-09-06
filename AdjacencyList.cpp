#include <string>
#include <iomanip>
#include <sstream>
#include "AdjacencyList.h"

using namespace std;

int AdjacencyList::addUpdateWebpage(const string& the_url, bool isit)
{
    // look for the url in the map
    auto findr = adjacentPages.find(the_url);
    int the_id;
    // if not found, add it with a new id
    if (findr == adjacentPages.end())
    {
        the_id = rankValue;
        // insert the url with the current rankValue then increment rankValue
        adjacentPages.insert(make_pair(the_url, rankValue++));
    }
    else
    {
        // if found, get the id from the map
        the_id = findr->second;
    }
    // check if we need to update the second map
    if (isit)
    {
        // if the url isn't in the second map, add it with a count of 1
        if (adjacentPages2.find(the_url) == adjacentPages2.end()) {
            adjacentPages2[the_url] = 1;
        } else {
            // if it's already there, increment the count
            adjacentPages2[the_url] += 1;
        }
    }
    // return the id for the url
    return the_id;
}

int AdjacencyList::addEdges(const string& from, const string& to)
{
    // getting id for the 'from' url, update if exists or add new
    int id_of_from = addUpdateWebpage(from, true);
    // doing the same for 'to' url
    int id_of_to = addUpdateWebpage(to, false);

    // checking if 'to' id already has an entry in the graph
    auto reaptr = adjacencyGraph.find(id_of_to);
    if (reaptr == adjacencyGraph.end())
    {
        // if not, we initialize an empty vector for it
        adjacencyGraph[id_of_to] = {};
    }
    // adding an edge from 'to' to 'from' with initial weight 0.0
    adjacencyGraph[id_of_to].push_back({id_of_from, 0.0});
    // checking and initializing for 'from' id similar to 'to' id above
    if (adjacencyGraph.find(id_of_from) == adjacencyGraph.end())
    {
        adjacencyGraph[id_of_from] = {};
    }

    // not really using the return value here, but it's 0 by default
    return 0;
}

string AdjacencyList::findPageUrlID(int webpage_number)
{
    // starting with an empty url string
    string websURL = "";
    // iterating through all pages to find the one with the given id
    auto otheriter = adjacentPages.begin();
    while (otheriter != adjacentPages.end()) {
        // if found, we set websURL to the url of the found page
        if (otheriter->second == webpage_number) {
            websURL = otheriter->first;
            break;
        }
        // moving to the next page
        ++otheriter;
    }
    // returning the found url or an empty string if not found
    return websURL;
}
// updating edge weights based on page ranks
void AdjacencyList::updateEdgeWeights()
{
    // loop thru each node in the graph
    for (auto& graph_node : adjacencyGraph)
    {
        // get the list of edges for the node
        auto& edges_list = graph_node.second;
        // loop thru each edge
        for (auto& edge : edges_list)
        {
            // get page id and url from the edge
            auto pageID = edge.first;
            auto pageURL = findPageUrlID(pageID);

            // check if we got a valid url
            if (pageURL.length() > 0)
            {
                // find the page in the adjacentPages2 map
                auto page_iter = adjacentPages2.find(pageURL);
                // if found, update the edge weight
                if (page_iter != adjacentPages2.end())
                {
                    edge.second = static_cast<double>(1) / page_iter->second;
                }
            }
        }
    }
}

//string AdjacencyList::printRank()
//{
//    auto the_repeat = adjacentPages.begin(); // Initialize the iterator to the beginning of the map
//    while (the_repeat != adjacentPages.end())
//    {
//        ostringstream x;
//        x << fixed << setprecision(2);
//        x << the_repeat->first << " " << powerIterations[the_repeat->second];
//        cout << x.str() << endl;
//        the_repeat++; // Move to the next element in the map
//    }
//}

string AdjacencyList::printRank()
{
    stringstream os;
    for (const auto& page : adjacentPages) //loop through each page
    {
        // append page url and its rank to the output
        os << page.first << " " << fixed << setprecision(2) << powerIterations[page.second] << "\n";
    }
    return os.str();
}


// main function to compute page rank
void AdjacencyList::computePageRank(int power_iterations)
{
    // initial setup
    int og = 0;
    // first update the weights of all edges
    updateEdgeWeights();
    // get the total number of pages
    int numberOPages = distance(adjacentPages.begin(), adjacentPages.end());
    // initialize power iterations for each page
    for (og = 1; og <= numberOPages; ++og)
    {
        powerIterations[og] = 1.0 / numberOPages;
    }
    // perform power iterations
    for (int otheriter2 = 0; otheriter2 < power_iterations - 1; ++otheriter2)
    {
        // temporary storage for this iteration's ranks
        map<int, double> tester;
        // loop thru each node in the graph
        for (const auto& the_node : adjacencyGraph)
        {
            // calculate total rank for the node
            double the_total = 0.0;
            for (const auto& an_edge : the_node.second)
            {
                // add the weighted rank from each incoming edge
                the_total = the_total + an_edge.second * powerIterations[an_edge.first];
            }
            // store the calculated rank
            tester[the_node.first] = the_total;
        }
        // update the main powerIterations map with the new ranks
        for (const auto& subst : tester)
        {
            powerIterations[subst.first] = subst.second;
        }
    }
    // finally, print the ranks
    printRank();
    cout << printRank() << endl;
}
