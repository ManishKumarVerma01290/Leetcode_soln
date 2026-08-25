class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq.insert(nums[i]);
        }
        int p = k;
        while(p >= k){
            if(freq.find(p) == freq.end()){
                return p;
            }
            p = p + k;
        }
        return -1;
    }
};