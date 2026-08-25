class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        int p = k;
        while(p >= k){
            for(auto i : freq){
                if(freq.find(p) == freq.end()){
                    return p;
                }
            }
            p = p + k;
        }
        return -1;
    }
};