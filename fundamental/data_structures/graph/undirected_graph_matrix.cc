#include <iostream>
using namespace std;


class Graph {
public:
    int matrix[20][20] = {}; //the adjacency matrix initially 0
    int count = 0;

    void addEdge (int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // for undirected graph
    }

    void display (int vertex) {
        int i, j;
        for(i = 0; i < vertex; i++) {
            for(j = 0; j < vertex; j++) {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main (int argc, char* argv[]) {
    int v = 6;
    Graph graph;
    graph.addEdge(0, 4);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(1, 5);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(5, 3);
    graph.addEdge(5, 4);
    graph.display(6);
    
    return 0;
}
