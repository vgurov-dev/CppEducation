/*
    242. Given two strings s and t, 
        return true if t is an anagram of s, 
        and false otherwise.

Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

Example 2:
    Input: s = "rat", t = "car"
    Output: false

 

Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

*/

#include <string>
#include <array>
#include <iostream>

#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::array<int, 26> letter_count{};

        if (s.length() != t.length()) { return false; }

        for (auto& letter : s) {
            letter_count[letter-'a']++;
        }

        for (auto& letter: t) {
            if (letter_count[letter-'a'] == 0) {
                return false;
            }
            letter_count[letter-'a']--;
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    std::string t_left = "soku";
    std::string t_right = "ukqs";

    bool result = sol.isAnagram(t_left, t_right);
    std::cout << result << std::endl;
    
    return result;
}