class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0,maxlen = 0;
        unordered_set<int>windows;
        for(int r = 0; r<s.size();r++){
            while(windows.count(s[r])){
                windows.erase(s[l]);
                l++;
            }
            windows.insert(s[r]);

            maxlen = max(maxlen, r-l+1);
        }
        return maxlen;
    }
};
