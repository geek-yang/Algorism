#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = 0;
        // sort input vectors
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = 0, j = 0; i < s.size() && j < g.size(); i++) {
            if (s[i] >= g[j]) {
                j++;
                n++;
            }
        }

        return n;
    }
};

int main () {
    // example 1
    vector<int> g_1{1,2,3};
    vector<int> s_1{1,2};

    Solution solver;
    int result = solver.findContentChildren(g_1, s_1);
    cout << result << endl;

    // example 2
    vector<int> g_2{1,2};
    vector<int> s_2{1,2,3};

    result = solver.findContentChildren(g_2, s_2);
    cout << result << endl;

    return 0;
}