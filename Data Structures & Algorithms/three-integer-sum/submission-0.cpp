#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& friends) {
        vector<vector<int>> successful_teams;
        
        // STEP 1: Line them up from most debt to most cash
        sort(friends.begin(), friends.end());
        
        // STEP 2: Pick the Team Captain
        for (int i = 0; i < friends.size(); i++) {
            
            // If this Captain has the exact same money as the last Captain, 
            // skip him so we don't create a duplicate team.
            if (i > 0 && friends[i] == friends[i - 1]) {
                continue;
            }
            
            // STEP 3: The Search for Teammates
            int left = i + 1;                  // Poorest available teammate
            int right = friends.size() - 1;    // Richest available teammate
            
            while (left < right) {
                // Combine their wallets
                int total_money = friends[i] + friends[left] + friends[right];
                
                if (total_money > 0) {
                    // Too rich! Move the right pointer to someone with less cash.
                    right--;
                } 
                else if (total_money < 0) {
                    // Too poor! Move the left pointer to someone with more cash.
                    left++;
                } 
                else {
                    // Exactly $0! We found a team.
                    successful_teams.push_back({friends[i], friends[left], friends[right]});
                    
                    // We found one team for this Captain, but there might be another.
                    // Tell the 'left' guy to step aside and check the next person.
                    left++;
                    
                    // Skip any clones (people with the exact same amount of money)
                    while (left < right && friends[left] == friends[left - 1]) {
                        left++;
                    }
                }
            }
        }
        
        return successful_teams;
    }
};