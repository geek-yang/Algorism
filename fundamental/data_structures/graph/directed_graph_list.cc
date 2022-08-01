#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int src, dest;
};

class Graph {
public:
    // vector to store the lists of graph
    vector<vector<int>> adjList;

    Graph (vector<Edge> const &edges, int n) {
        adjList.resize(n);
        // add edges to the directed graph
        for (auto &edge: edges) {
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
            // uncomment the following code for undirected graph
            // adjList[edge.dest].push_back(edge.src);
        }
    }

    void printGraph(int n) {
        for (int i = 0; i < n; i++)
        {
            // print the current vertex number
            cout << i << " ——> ";
 
            // print all neighboring vertices of a vertex `i`
            for (int v: adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }        
    }
};

int main () {
    // vector of graph edges as per the above diagram.
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
    // total number of nodes in the graph (labelled from 0 to 5)
    int n = 6;
    // construct graph
    Graph graph(edges, 6);

    // print graph
    graph.printGraph(n);

    return 0;
}