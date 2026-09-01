/*
    28. Find the Index of the First Occurrence in a String
    https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
    Given two strings needle and haystack, 
        return the index of the first occurrence of needle in haystack, 
        or -1 if needle is not part of haystack.

    Example 1:
        Input: haystack = "sadbutsad", needle = "sad"
        Output: 0
        Explanation: "sad" occurs at index 0 and 6.
        The first occurrence is at index 0, so we return 0.

    Example 2:
        Input: haystack = "leetcode", needle = "leeto"
        Output: -1
        Explanation: "leeto" did not occur in "leetcode", so we return -1.
    
    Constraints:
        1 <= haystack.length, needle.length <= 104
        haystack and needle consist 
            of only lowercase English characters.
*/

#include <string>
#include <iostream>
#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'


using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int first_idx = -1; 
        int idx = 0;

        while ((int)(haystack.size() - needle.size()) >= idx) { 
            if (needle[0] == haystack[idx]) {
                int n_idx = 0;
                int mem_compare_idx = 0;
                mem_compare_idx = idx;
                bool is_breaked = false;
                while (n_idx <= (int)needle.size() - 1) {
                    if(needle[n_idx] != haystack[idx + n_idx]) {
                        is_breaked = true;
                        break;
                    }
                    n_idx++;
                }
                if (!is_breaked) {
                    return mem_compare_idx; 
                }   
            }
            idx++;
        }
        return first_idx;
    }
};

int main() {
    Solution sol;

    int result = sol.strStr("testdrone", "dron");
    DEBUG(result);

    result = sol.strStr("melone", "mel");
    DEBUG(result);

    result = sol.strStr("melinmelmelon", "melon");
    DEBUG(result);
    
    return 0;
}