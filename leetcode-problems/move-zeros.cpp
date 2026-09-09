/*
    283. Move Zeros 

    Given an integer array nums, move all 0's to 
        the end of it while maintaining the relative order 
        of the non-zero elements.

    Note that you must do this in-place without making 
    a copy of the array.

    Example 1:
        Input: nums = [0,1,0,3,12]
        Output: [1,3,12,0,0]
    Example 2:
        Input: nums = [0]
        Output: [0]
*/

#include <iostream>
#include <vector>


void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
#define DEBUG(x) printVector(x)
#define DEBUG_var(x) std::cout << #x << " = " << (x) << '\n'



using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) { 
        int idx = 0;
        int slot = -1;
        while (idx < nums.size()) {
            int value = nums[idx];
            if (nums[idx] != 0) {
                slot++;
                if(slot !=idx) {
                    nums[idx] = 0;
                }
                nums[slot] = value;
            }
            idx++;
        }
    }
};



int main() {
    Solution sol;

    vector<int> result1 = {0, 1, 2, 0, 1};
    sol.moveZeroes(result1);
    DEBUG(result1);

    vector<int> result2 = {0, 1, 2, 1, 0};
    sol.moveZeroes(result2);
    DEBUG(result2);

    vector<int> result3 = {0, 1, 0, 102, 0, 1, 0, 100};
    sol.moveZeroes(result3);
    DEBUG(result3);

    vector<int> result4 = {0};
    sol.moveZeroes(result4);
    DEBUG(result4);

    vector<int> result5 = {1};
    sol.moveZeroes(result5);
    DEBUG(result5);

    vector<int> result6 = {1, 1};
    sol.moveZeroes(result6);
    DEBUG(result6);

    vector<int> result7 = {1, 1, 0, 1};
    sol.moveZeroes(result7);
    DEBUG(result7);
    
    vector<int> result8 = {0, 1};
    sol.moveZeroes(result8);
    DEBUG(result8);
    
    return 0;
}