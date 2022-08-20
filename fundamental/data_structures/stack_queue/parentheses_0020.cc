#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    bool paratheses (string s) {
        stack<char> count;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') count.push('}');
            else if (s[i] == '(') count.push(')');
            else if (s[i] == '[') count.push(']');
            else if (count.empty() || count.top() != s[i]) return false;
            else count.pop();
        }
        return count.empty();
    }
};

int main () {
    // test
    string s = "([])";
    Solution solver;
    cout << solver.paratheses(s) << endl;
    return 0;
}