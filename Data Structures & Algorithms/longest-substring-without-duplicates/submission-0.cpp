#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // MEMORY MAP: An array of size 128 to represent all standard ASCII characters.
        // It stores the exact index where we LAST SEEN each character.
        // We initialize all slots to -1 (meaning "we haven't seen this character yet").
        vector<int> last_seen(128, -1);
        
        int max_length = 0;
        int left = 0; // The left boundary of our sliding window
        
        // The right boundary of our sliding window expands one character at a time.
        for (int right = 0; right < s.length(); right++) {
            char current_char = s[right];
            
            // QUESTION 1: Have we seen this character before, AND is its last known 
            // location still inside our active window?
            if (last_seen[current_char] >= left) {
                // If yes, our current window has a duplicate and is invalid.
                // We instantly shrink the window by pulling the left boundary 
                // just past the old duplicate's location.
                left = last_seen[current_char] + 1;
            }
            
            // Step 2: Now that the window is valid again, update the memory map 
            // with the new, current location of this character.
            last_seen[current_char] = right;
            
            // Step 3: Calculate the size of our valid window. 
            // (Right index - Left index + 1 gives the total count of characters).
            int current_window_size = right - left + 1;
            
            // Step 4: Does this valid window beat our historical high score?
            if (current_window_size > max_length) {
                max_length = current_window_size;
            }
        }
        
        return max_length;
    }
};