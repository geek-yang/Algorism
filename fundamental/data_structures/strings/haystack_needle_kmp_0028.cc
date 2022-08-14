#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    void getNext (vector<int>& next, string needle) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < needle.size(); i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> next(needle.size(), 0);
        getNext(next, needle);
        int j = 0; // similar to getNext, we will use Next vector
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main () {
    // test
    string haystack = "hello";
    string needle = "ll";
    Solution solver;
    int result = solver.strStr(haystack, needle);
    cout << result << endl;

    return 0;
}