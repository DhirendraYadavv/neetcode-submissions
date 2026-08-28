#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // MEMORY SLOT 1: The cheapest price we have seen so far.
        // We initialize this to the maximum possible integer. Why? 
        // So that the very first stock price we check will automatically 
        // be lower than this, becoming our first 'cheapest price'.
        int min_price = INT_MAX; 
        
        // MEMORY SLOT 2: Our "High Score" for profit.
        // We start at 0. If the stock market crashes every single day, 
        // we simply choose not to buy anything, leaving us with 0 profit.
        int max_profit = 0;      
        
        // Walk through the timeline of prices, day by day.
        for (int i = 0; i < prices.size(); i++) {
            int current_price = prices[i];
            
            // QUESTION 1: Is today a new historical low?
            if (current_price < min_price) {
                // If yes, erase our old memory and record today's price 
                // as the new cheapest price to buy at.
                min_price = current_price; 
            } 
            
            // QUESTION 2: If today is NOT a new low, can we make a record profit?
            else {
                // How much would we make if we bought at our memorized lowest 
                // price, and sold at today's price?
                int profit_if_sold_today = current_price - min_price;
                
                // Does this profit beat our previous High Score?
                if (profit_if_sold_today > max_profit) {
                    // If yes, update the High Score!
                    max_profit = profit_if_sold_today; 
                }
            }
        }
        
        // Once we finish walking through the timeline, our 'max_profit' variable 
        // will hold the absolute highest profit we found.
        return max_profit;
    }
};