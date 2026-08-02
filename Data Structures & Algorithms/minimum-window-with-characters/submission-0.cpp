class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){
            return "";
        }

        vector<int>targetfreq(128,0);
        vector<int>windowfreq(128,0);

        for(char c:t){
            targetfreq[c]++;
        }
        int required = t.length();
        int left=0;
        int minlen=INT_MAX;
        int start=0;

        for(int right=0;right<s.length();right++){
            char c=s[right];
            windowfreq[c]++;

            if(targetfreq[c] > 0 && windowfreq[c] <= targetfreq[c]){
                required--;
            }

            while(required==0){

                if(right-left+1<minlen){
                    minlen = right-left+1;
                    start = left;
                }
                char leftchar = s[left];
                windowfreq[leftchar]--;

                if(targetfreq[leftchar]>0 && windowfreq[leftchar]<targetfreq[leftchar]){
                    required++;
                }
                left++;
            }
        }

        if(minlen == INT_MAX)
            return "";

        return s.substr(start, minlen);
    }
};
