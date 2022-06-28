#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s){
        for(int i = 0, j = s.size() - 1; i < j;){
            char k = s[i];
            s[i] = s[j];
            s[j] = k;
            i++;
            j--;
        }
    }
};

int main () {
    // test case
    string s = "experiment";
    vector<char> c(s.begin(), s.end());

    for (const char &p: c) {
        cout << p;
    }

    cout << "\n" << "reverse strings" << endl;

    Solution solver;
    solver.reverseString(c);

    for (const char &p: c) {
        cout << p;
    }    

    return 0;
}
