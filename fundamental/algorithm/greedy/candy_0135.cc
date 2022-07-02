#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy (vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        // loop from left
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i] < ratings[i+1]) {
                candy[i+1] = candy[i] + 1;
            }
        }

        // loop from right
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i] < ratings[i-1]) {
                candy[i-1] = max(candy[i-1], candy[i] + 1);
            }
        }

        int sum = accumulate(candy.begin(), candy.end(), 0);

        return sum;
    }
};

int main () {
    // example 1
    vector<int> children{1,0,2};
    Solution solver;

    int sum = solver.candy(children);
    cout << sum << endl;

    // example 2
    children = {1,2,2};
    sum = solver.candy(children);
    cout << sum << endl;

    // example 3
    children = {1,3,2,2,1};
    sum = solver.candy(children);
    cout << sum << endl;

    // example 4
    children = {1,2,87,87,87,2,1};
    sum = solver.candy(children);
    cout << sum << endl;

    return 0;
}