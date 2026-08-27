#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Start from the rightmost digit (least significant digit)
        // just like standard grade-school addition.
        for (int i = digits.size() - 1; i >= 0; --i) {
            
            // CASE 1: The digit is between 0 and 8.
            // Adding 1 won't create a carry (e.g., 4 + 1 = 5).
            // We can just increment it and return the result immediately.
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // CASE 2: The digit is exactly 9.
            // Adding 1 makes it 10. We can't put 10 in a single slot.
            // So, we leave a 0 here, and let the loop continue to the 
            // next digit on the left to "carry the 1".
            digits[i] = 0;
        }
        
        // CASE 3: We finished the loop but never returned.
        // This ONLY happens if every single digit was a 9 (e.g., [9, 9, 9]).
        // The array is currently filled with zeros (e.g., [0, 0, 0]).
        // The real answer should be 1000, so we need an array of [1, 0, 0, 0].
        
        // OPTIMIZATION: Instead of using digits.insert(digits.begin(), 1) 
        // which takes O(n) time to shift all elements to the right,
        // we just add a 0 to the very end of the array...
        digits.push_back(0); 
        
        // ...and change the first element to a 1. 
        // [0, 0, 0] -> push_back(0) -> [0, 0, 0, 0] -> set index 0 to 1 -> [1, 0, 0, 0]
        digits[0] = 1;
        
        return digits;
    }
};