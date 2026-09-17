class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxLen = 0;
        int maxFreq = 0;
        int i = 0, j = 0;
        while(j < s.size()){
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            while((j - i + 1) - maxFreq > k){
                mp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};