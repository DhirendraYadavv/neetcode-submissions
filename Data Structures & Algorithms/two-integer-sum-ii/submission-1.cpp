#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& line_of_girls, int target_vibe) {
        
        // STEP 1: POSITION YOUR WINGMEN
        // Put one guy at the very front (the chillest girl)
        int left_wingman = 0; 
        
        // Put the other guy at the very back (the wildest girl)
        int right_wingman = line_of_girls.size() - 1; 
        
        // STEP 2: TEST THE VIBE
        // Keep checking until they pinpoint the perfect duo
        while (left_wingman < right_wingman) {
            
            // What happens if we put these two girls in the same car?
            int combined_vibe = line_of_girls[left_wingman] + line_of_girls[right_wingman];
            
            // SCENARIO A: IT'S A PERFECT MATCH
            if (combined_vibe == target_vibe) {
                // The prompt says the line is "1-indexed" (normal people counting).
                // So we add +1 to their index before we walk away with them.
                return {left_wingman + 1, right_wingman + 1};
            }
            
            // SCENARIO B: THE VIBE IS TOO CRAZY (> target)
            else if (combined_vibe > target_vibe) {
                // The chill girl (left) can't possibly get any chillier.
                // The only way to lower the energy is to tell the right wingman 
                // to step away from the wildest girl and move one spot to the left.
                right_wingman--;
            }
            
            // SCENARIO C: THE VIBE IS TOO BORING (< target)
            else {
                // The wild girl (right) can't possibly get any wilder.
                // The only way to raise the energy is to tell the left wingman 
                // to skip the chillest girl and move one spot to the right.
                left_wingman++;
            }
        }
        
        return {}; // (The problem guarantees a solution, so we never actually hit this)
    }
};