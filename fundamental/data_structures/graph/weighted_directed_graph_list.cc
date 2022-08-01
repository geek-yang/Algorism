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
};

int main () {
    return 0;
}