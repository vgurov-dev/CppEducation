/* 
    35. Search Insert Position
    Given a sorted array of distinct integers and a target value, 
        return the index if the target is found. 
    If not, return the index where it would be if it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:
        Input: nums = [1,3,5,6], target = 5
        Output: 2
    
    Example 2:
        Input: nums = [1,3,5,6], target = 2
        Output: 1
    
    Example 3:
        Input: nums = [1,3,5,6], target = 7
        Output: 4
*/
#include <vector>
#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        std::cout << "target: " << target << std::endl;
        std::cout << "nums: ";
        for (const auto& n : nums) {
            std::cout << n << " ";
        }
        int index_start = 0;
        int index_end = static_cast<int>(nums.size()) - 1;

        // [0, 1, 2, 3]
        // [0, 1, 2, 3, 4]
        while(index_start <= index_end) {
            std::cout << "Прогон" << std::endl;
            std::cout << "index_start" << index_start << std::endl;
            std::cout << "index_end: " << index_end << std::endl;
     

            int index_mid = index_start + (index_end - index_start) / 2;

            std::cout << "index_mid: " << index_mid << std::endl;
            std::cout << "nums[index_mid]: " << nums[index_mid] << std::endl;
            std::cout << "\n" << std::endl;

            if (nums[index_mid] > target) {
                index_end = index_mid - 1;
            }
            else if (nums[index_mid] < target) {
                index_start = index_mid + 1;
            }
            else {
                return index_mid;
            }
        }
        return index_start;
    }  
};

int main() {
    Solution solution;

    std::vector<int> v = {1, 3, 100, 4392, 110000};
    int target = 2;
    
    int result = solution.searchInsert(v, target);
    std::cout << result << std::endl;

    return 0;
}