class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int Min = INT_MAX, Max = INT_MIN;
        for(int i = 0; i < n; i++){
            Min = min(Min, nums[i]);
            Max = max(Max, nums[i]);
        }
        unordered_set<int> temp(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = Min; i <= Max; i++){
            if(temp.find(i) == temp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};