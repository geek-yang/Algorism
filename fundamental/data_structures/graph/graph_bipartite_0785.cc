#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
/* Check if a graph is bipartite.*/
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (graph.empty()) return true;
        vector<int> color(n, 0);
        // for BFS
        queue<int> q;
        for (int i = 0; i < n; i ++) {
            // traverse vertex
            // 0 is not checked, 1 and 2 are colors
            if (!color[i]) {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty()) {
                // check edge
                int node = q.front();
                q.pop();
                for (const int &j: graph[node]) {
                    if (color[j] == 0) {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;
                    }
                    else if (color[node] == color[j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main () {
    // vector of graph edges as per the above diagram.
    vector<vector <int>> graph =
    {
        {1, 3}, {0, 2}, {1, 3}, {0, 2}
    };
    Solution solver;
    bool checker = solver.isBipartite(graph);
    cout << checker << endl;
    return 0;
}