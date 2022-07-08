#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen (int target, vector<int>& nums) {
        int count = INT32_MAX;
        int sum = 0;
        int i = 0; // starting point slide window
        int window_len = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                window_len = j - i + 1;
                count = count > window_len ? window_len : count;
                sum -= nums[i++]; 
            }
        }
        return count == INT32_MAX? 0 : count;
    }

    int minSubArrayLen_brute (int target, vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return 1;
            }
            else {
                sum = nums[i];
                int temp_count = 1;
                for (int j = i + 1; j < nums.size(); j++) {
                    sum += nums[j];
                    temp_count++;
                    if (sum >= target) {
                        if (count > temp_count || count == 0) {
                            count = temp_count;
                            continue;
                        }
                    }
                }
            }
        }
        return count; 
    }

    int minSubArrayLen_brute_clean (int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int i = 0;
        int subLength = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                subLength = (j - i + 1);
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; 
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main () {
    // example input 1
    vector<int> array_1{2,3,1,2,4,3};
    int target = 7;

    Solution solver;
    int result = solver.minSubArrayLen(target, array_1);
    cout << result << endl;

    // example input 2
    vector<int> array_2{1,1,1,1,1,1,1,1};
    target = 11;
    result = solver.minSubArrayLen(target, array_2);
    cout << result << endl;

}