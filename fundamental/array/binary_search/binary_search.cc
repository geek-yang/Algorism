#include <iostream>
#include <vector>
using namespace std;

class Solution {
/* Solution for leetcode question 704.

For binary search, it is a must that the given input
array is sorted in ascending order and there is no
repeated element.

 */
public:
    int binary_search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }

        return -1;
    }

    void vector_print(vector<int>& nums, int size){
    for (int i = 0; i < size; i++){
        std::cout << nums[i] << ' ';
    }
    std::cout << "\n" << std::endl;
    }
};

int main()
{
    // first checker
    vector<int> nums {-1,0,3,5,9,12};
    int target = 9;
    Solution solution;
    std::cout << "First test.\n";
    std::cout << "Test data.\n";
    solution.vector_print(nums, nums.size());
    
    int result;
    result = solution.binary_search(nums, target);
    std::cout << "Output:" << result << "\n";


    std::cout << "------------------------------\n";

    // second checker
    target = 2;
    std::cout << "Second test.\n";
    std::cout << "Output.\n";
    result = solution.binary_search(nums, target);
    std::cout << "Output:" << result << "\n";
}