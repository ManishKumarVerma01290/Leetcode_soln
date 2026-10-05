class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        if(n > 1){
            dp[1] = max(nums[0], nums[1]);
        }
        for(int idx = 2; idx < n; idx++){
            int take = 0, ntake = 0;
            if(idx > 1){
                take += nums[idx] + dp[idx - 2];
            }
            ntake += dp[idx - 1];
            dp[idx] = max(take, ntake);
        }
        return dp[n - 1];
    }
};