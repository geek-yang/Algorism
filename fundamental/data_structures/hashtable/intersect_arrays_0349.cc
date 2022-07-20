#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersectArrays (vector<int> nums1, vector<int> nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num: nums2) {
            if (nums_set.find(num) != nums_set.end()) { // check iterator
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main () {
    // test example
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    Solution solver;
    vector<int> results = solver.intersectArrays(nums1, nums2);
    for (auto i: results) cout << i << ' ';
    cout << endl;
    
    return 0;
}