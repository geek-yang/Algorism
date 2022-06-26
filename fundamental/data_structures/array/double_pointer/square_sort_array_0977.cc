#include <iostream>
#include <vector>
using namespace std;

class Solution{
    /* Solution for leetcode question 977
    make sure that the input is sorted.*/
public:
    vector<int> square_sort(vector<int>& nums) {
        int count = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        int left_square;
        int right_square;
        for (int i = 0, j = nums.size() - 1; j >= i;){
            left_square = nums[i] * nums[i];
            right_square = nums[j] * nums[j];
            if (left_square < right_square){
                result[count--] = right_square;
                j--;
            }
            else {
                result[count--] = left_square;
                i++;
            }
        }
        return result;
    }

    void print_array(vector<int>& nums){
        for (int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << "\n" << endl;
    }
};

int main () {
    // create a solver
    Solution solver;
    // test case 1
    cout << "test case 1" << endl;
    vector<int> test_1{-4,-1,0,3,10};
    vector<int> results;
    results = solver.square_sort(test_1);
    solver.print_array(results);
    // test case 2
    cout << "test case 2" << endl;
    vector<int> test_2{-7,-3,2,3,11};
    results = solver.square_sort(test_2);
    solver.print_array(results);

    return 0;
}