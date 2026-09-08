class Solution {
public:
    int solve(vector<int>& nums, int i){
        int ans = INT_MAX;
        for(int k = i; k < nums.size(); k++){
            ans = min(ans, nums[k]);
        }
        return ans;
    }
    int firstStableIndex(vector<int>& nums, int k) {
        int Min = INT_MAX, Max = nums[0], n = nums.size();
        int ans = INT_MAX;
        bool flag = false;
        Min = solve(nums, 0);
        for(int i = 0; i < n; i++){
            Max = max(Max, nums[i]);
            if(flag){
                Min = solve(nums, i);
                flag = false;
            }
            if(Max - Min <= k){
                ans = min(ans, i);
            }
            if(nums[i] == Min){
                flag = true;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};