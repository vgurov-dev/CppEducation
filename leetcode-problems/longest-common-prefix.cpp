/*
    14. Longest Common Prefix
    
    Write a function to find the longest
    common prefix string amongst an array 
    of strings.

    If there is no common prefix
        , return an empty string "".

    Example 1:
        Input: strs = ["flower","flow","flight"]
        Output: "fl"

    Example 2:
        Input: strs = ["dog","racecar","car"]
        Output: ""

        Explanation: There is no common prefix among 
            the input strings.

*/
#include <string>
#include <vector>
#include <iostream>
#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        int min_letters_count = strs[0].size();
        int idx = 0;
        string prefix_result  = "";

        while (idx < min_letters_count) {
            char base_c = strs[0][idx];
            
            for (size_t word_idx = 1; word_idx < strs.size(); word_idx++) {
                if (idx == 0) {
                    size_t word_size = strs[word_idx].size();

                    if (min_letters_count > word_size) {
                        min_letters_count = word_size;
                    }
                }
                if (strs[word_idx][idx] != base_c) {
                    return prefix_result;
                }
            }
            
            prefix_result += base_c;
            idx++;
        }

        return prefix_result;
    }
};

            
int main() {
    Solution solution;
    
    vector<string> s = {"file", "fine", "fire"};
    string result = solution.longestCommonPrefix(s);
    std::cout << result << std::endl;
    DEBUG(result);
    
    s = {"Vlad"};
    result = solution.longestCommonPrefix(s);
    cout << result << endl;
    DEBUG(result);

    s = {"brp", "brm", "wow"};
    result = solution.longestCommonPrefix(s);
    cout << result << endl;
    DEBUG(result);

    return 0;
}
    