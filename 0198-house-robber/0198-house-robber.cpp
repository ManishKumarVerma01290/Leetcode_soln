class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0){
            return nums[idx];
        }
        if(idx < 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take = 0, ntake = 0;
        if(idx > 0){
            take += nums[idx] + solve(idx - 2, nums, dp);
        }
        ntake += solve(idx - 1, nums, dp);
        return dp[idx] = max(take, ntake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(n - 1, nums, dp);
    }
};