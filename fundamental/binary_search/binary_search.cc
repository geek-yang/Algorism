#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // void binary_search(vector<int>& nums, int target) {
    //     target = ;

    // }

    void vector_print(vector<int>& nums, int size){
    for (int i = 0; i < size; i++){
        std::cout << nums[i] << ' ';
    }
    std::cout << "\n" << std::endl;
    }
};

int main()
{
    vector<int> nums {-1,0,3,5,9,12};
    int target = 9;
    Solution solution;
    solution.vector_print(nums, nums.size());
}