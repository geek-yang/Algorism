#include <iostream>
#include <vector>
using namespace std;

// https://www.techiedelight.com/graph-implementation-using-stl/

// Data structure to store a graph edge
struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph {
public:
    // a vector of vectors of Pairs to represent an adjacency list
    vector<vector<Pair>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int n) {
        // resize the vector to hold `n` elements of type vector<Edge>
        adjList.resize(n);
        // add edges to the directed graph
        for (auto &edge: edges)
        {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
 
            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));
 
            // uncomment the following code for undirected graph
            // adjList[dest].push_back(make_pair(src, weight));
        }        
    }

    void printGraph(int n) {
        for (int i = 0; i < n; i++) {
            for (Pair v: adjList[i]) {
                cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }
};

int main () {
    vector<Edge> edges =
    {
        // (x, y, w) —> edge from `x` to `y` having weight `w`
        {0, 1, 6}, {1, 2, 7}, {2, 0, 5}, {2, 1, 4}, {3, 2, 10}, {5, 4, 1}, {4, 5, 3}
    };

    // total number of nodes in the graph (labelled from 0 to 5)
    int n = 6;

    // construct graph
    Graph graph(edges, n);

    graph.printGraph(n);

    return 0;
}