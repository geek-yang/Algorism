#include <iostream>
#include <vector>
using namespace std;

class Solution {
/* Solution for leetcode question 27 */
public:
    int remove_element_dual_pointer (vector<int>& nums, int target) {
        int slowindex = 0;
        for (int fastindex = 0; fastindex < nums.size(); fastindex++) {
            if (target != nums[fastindex]) {
                nums[slowindex++] = nums[fastindex];
            }
        }
        return slowindex;
    }

    int remove_element_brute_force (vector<int>& nums, int target) {
        // time complexity：O(n^2)
        // space complexity：O(1)
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == target) {
                for (int j = i; j < size - 1; j++) {
                    nums[j] = nums[j+1];
                }
                i--;
                size--;
            }
        }
        return size;
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
    cout << "The array for test case 1 is:" << endl;
    solver.print_input(nums);

    //int result = solver.remove_element_brute_force(nums, val);
    int result = solver.remove_element_dual_pointer(nums, val);
    cout << "The length is " << result << endl;
    solver.print_input(nums);

    // test case 2
    nums = {0,1,2,2,3,0,4,2};
    val = 2;

    cout << "The array for test case 2 is:" << endl;
    solver.print_input(nums);
        
    //result = solver.remove_element_brute_force(nums, val);
    result = solver.remove_element_dual_pointer(nums, val);
    cout << "The length is " << result << endl;
    solver.print_input(nums);
}