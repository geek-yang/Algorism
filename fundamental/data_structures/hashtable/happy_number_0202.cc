#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int getSum (int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sum_list;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) return true;
            if (sum_list.find(sum) != sum_list.end()) return false;
            else sum_list.insert(sum);
            n = sum;
        }
    }
};

int main () {
    // test example
    int n = 19;
    bool check;
    Solution solver;
    check = solver.isHappy(n);
    cout << check << endl;
    return 0;
}