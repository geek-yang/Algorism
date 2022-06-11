#include <iostream>
#include <vector>
using namespace std;

class Solution {
/* Solution for leetcode question 27 */
public:
    int remove_element_smart (vector<int>& nums, int target) {
        //something TBA
        return -1;
    }

    int remove_element_brute_force (vector<int>& nums, int target) {
        return -1;
    }

    void print_input (vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n" << endl;
    }
};

int main () {
    // test case 1
    vector<int> nums{3,2,2,3};
    int val = 3;

    Solution solver;
    solver.print_input(nums);

    // test case 2
    nums = {0,1,2,2,3,0,4,2};
    val = 2;
}