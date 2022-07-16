#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fibonacci(int n) {
        int f0 = 0;
        int f1 = 1;
        if (n == 0) return f0;
        else if (n == 1) return f1;
        else {
                int fn = fibonacci(n-1) + fibonacci(n-2);
                return fn;
            }
    }
};

int main () {
    // sample 1
    int n = 2;
    int result;
    Solution solver;
    result = solver.fibonacci(n);
    cout << result << endl;

    // sample 2
    n = 3;
    result = solver.fibonacci(n);
    cout << result << endl;

    // sample 3
    n = 4;
    result = solver.fibonacci(n);
    cout << result << endl;

    return 0;
}