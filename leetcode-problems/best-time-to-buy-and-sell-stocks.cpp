/* 
You are given an array prices where prices[i] 
    is the price of a given stock on the ith day.

You want to maximize your profit by choosing 
    a single day to buy one stock 
    and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) 
    and sell on day 5 (price = 6), 
    profit = 6-1 = 5.
Note that buying on day 2 
    and selling on day 1 is not allowed 
    because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions 
    are done and the max profit = 0.


*/

#include <vector>
#include <limits>
#include <iostream>

#define DEBUG(x) std::cout << #x << " = " << (x) << '\n'

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_delta = std::numeric_limits<int>::min(); // -2147483648;
        int min_buy_price = prices[0];

        for (auto& price : prices) {
            DEBUG(min_buy_price);
            DEBUG(max_delta);

            std::cout << "Начало итерации" << '\n';      
            min_buy_price = min(price, min_buy_price);
            
            int delta = price - min_buy_price;
            DEBUG(delta);

            if (delta > max_delta) {
                max_delta = delta;
            }

            std::cout << "Конец итерации" << '\n' << '\n';                     
        }
        return max_delta;
    }
private:
    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};

int main() {
    Solution sol;
    std::vector<int> prices_input = {100, 20, 150, 40, 1};
    int result = sol.maxProfit(prices_input);
    
    return 0;
}

