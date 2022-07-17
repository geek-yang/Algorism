#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string& s) {
        removeExBlank(s);
        reverse(s, 0, s.size() - 1);
        // find single word and reverse
        int letter_1st = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s, letter_1st, i - 1);
                letter_1st = i + 1;
            }
        }
        // for the last word
        reverse(s, letter_1st, s.size() - 1);

        return s;
    }

    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--)
            swap(s[i], s[j]);
    }

    void removeExBlank(string& s) {
        int slowIndex = 0, fastIndex = 0;
        // remove trailing blank
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ')
            fastIndex++;
        // remove extra blank in-between
        for (; fastIndex < s.size(); fastIndex++) {
            if (fastIndex - 1 > 0 && s[fastIndex] == s[fastIndex - 1] && s[fastIndex] == ' ')
                continue;
            else s[slowIndex++] = s[fastIndex];
        }
        // remove tail blank
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ')
            s.resize(slowIndex - 1);
        else s.resize(slowIndex);
    }
};

int main () {
    // test string
    string case_1 = " the sky is blue ";
    Solution solver;
    solver.reverseWords(case_1);
    cout << case_1;

    return 0;
}