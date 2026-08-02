class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }

        vector<int>s1freq(26,0);
        vector<int>windowfreq(26,0);
        
        for(char c:s1){
            s1freq[c -'a']++;
        }

        int left = 0;

        for(int right=0;right<s2.length();right++){
            windowfreq[s2[right]-'a']++;

            if(right-left+1>s1.length()){
                windowfreq[s2[left]-'a']--;
                left++;
            }

            if(s1freq==windowfreq){
                return true;
            }
        }
        return false;
    }
};
