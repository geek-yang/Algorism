#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            if (s.size() >= i + k) reverse(s, i, i + k - 1);
            else reverse(s, i, s.size() - 1);
        }
        return s;
    }

    void reverse(string& s, int start, int end) {
        // it can be replaced by reverse(s.begin(), s.end());
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }
};

int main () {
    // test sample 1
    string s_1 = "abcdefg";
    int k = 2;
    Solution solver;
    string s = solver.reverseStr(s_1, k);
    cout << s;
    cout << endl;

    return 0;
}
