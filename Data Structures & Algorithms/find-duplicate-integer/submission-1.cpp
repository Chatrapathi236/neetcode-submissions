class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>numbers;
        for(int n : nums){
            if(numbers.count(n)){
                return n;
            }
            numbers.insert(n);
        }
        return -1;
    }
};
