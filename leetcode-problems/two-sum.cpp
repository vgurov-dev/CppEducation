#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size(); j++) {
                if (j == i) {
                    continue;
                }
                else {
                    if(nums[i] + nums[j] == target) {
                        std::vector<int> result = {(int)i, (int)j};
                        return result;
                    }
                }
            }
        }
        return {};
    }
};


int main() {
    Solution solution;
    
    std::vector<int> v = {1, 2, 3, 4, 5};
    int target = 5;
    
    std::vector<int> result = solution.twoSum(v, target);
    for (int val : result) {
        std::cout << val << " ";
    }

    std::cout << std::endl; 

    return 0;
}