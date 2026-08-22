#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // 1. Create our "filing cabinet"
        unordered_map<string, vector<string>> anagramMap;
        
        // 2. Sort every word and place it in the correct folder
        for (string word : strs) {
            
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            anagramMap[sortedWord].push_back(word);
        }
        
        // 3. Create a box to hold our final answer
        vector<vector<string>> result;
        
        // 4. Empty the folders from the cabinet into our final box
        // (Using const auto& is faster because it looks at the original folder 
        // without making a temporary copy of it first)
        for (const auto& pair : anagramMap) {
            result.push_back(pair.second); 
        }
        
        // 5. Hand the box back to LeetCode!
        return result;
    }
};