/*
    125. A phrase is a palindrome if, 
        after converting all uppercase letters into lowercase letters 
        and removing all non-alphanumeric characters, 
        it reads the same forward and backward. 
        Alphanumeric characters include letters and numbers.
    Given a string s, return true if it is a palindrome, or false otherwise.

    Example 1:
        Input: s = "A man, a plan, a canal: Panama"
        Output: true
        Explanation: "amanaplanacanalpanama" is a palindrome.
    
    Example 2:
        Input: s = "race a car"
        Output: false
        Explanation: "raceacar" is not a palindrome.
    
    Example 3:
        Input: s = " "
        Output: true
        Explanation: s is an empty string "" after 
            removing non-alphanumeric characters.
        Since an empty string reads the same forward and backward, 
            it is a palindrome.
*/

#include <iostream>
#include <string>
#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'



class Solution {
public:
    bool isPalindrome(std::string s) {
        size_t str_len = s.size();
        int left = 0;
        int right = str_len - 1;

        while (left < right) {
            if (!isValid(s[left])) {
                while(!isValid(s[left]) && (left < right)) {
                    left++;
                }
            }
            if (!isValid(s[right])) {
                while(!isValid(s[right]) && (left < right)) {
                    right--;
                }
            }
            if (letterTransform(s[left]) != letterTransform(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        
        return true;
    }
private:
    bool isValid(char c) {
        return ('a' <= c && c <= 'z') 
            || ('A' <= c && c <= 'Z') 
            || ('0' <= c && c <= '9');
    }
    char letterTransform(char c) {
        if('A' <= c && c <= 'Z') {
            return c+32;
        }
        return c;
    }
};

int main() {
    Solution solution;
    
    std::string s = "{2a, 4b, 5 ,b4,a2}";
    bool result = solution.isPalindrome(s);
    std::cout << result << std::endl;
    DEBUG(s);
    DEBUG(result);
    
    s = "QaZ~abbddddbba)zaq";
    result = solution.isPalindrome(s);
    std::cout << result << std::endl;
    DEBUG(s);
    DEBUG(result);

    s = "Q11_1Q";
    result = solution.isPalindrome(s);
    std::cout << result << std::endl;
    DEBUG(s);
    DEBUG(result);

    s = "Q11_1Q";
    result = solution.isPalindrome(s);
    std::cout << result << std::endl;
    DEBUG(s);
    DEBUG(result);

    return 0;
}
