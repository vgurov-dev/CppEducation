/*
    You are given an array of integers nums and an integer target, 
        return indices of the two numbers 
        such that they add up to target.
    You may assume that each input would have exactly 
        one solution, and you may not use the same element twice.
    You can return the answer in any order.

    Example 1:
        Input: nums = [2,7,11,15], target = 9
        Output: [0,1]
        Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    Example 2:
        Input: nums = [3,2,4], target = 6
        Output: [1,2]

    Example 3:
        Input: nums = [3,3], target = 6
        Output: [0,1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; 
        
        for (size_t i = 0; i < nums.size(); i++) {
            int delta = target - nums[i];
             
            auto it = seen.find(delta);
            if (it != seen.end()) {
                int first_index = it->second;
                return {first_index, (int)i};
            }
            else 
            {
                seen.insert({nums[i], i});
            }
        }
        return {};
    }
};


int main() {
    Solution solution;
    
    std::vector<int> v = {1, 2, 5, 4, 3};
    int target = 5;
    
    std::vector<int> result = solution.twoSum(v, target);
    for (int val : result) {
        std::cout << val << " ";
    }

    std::cout << std::endl; 

    return 0;
}