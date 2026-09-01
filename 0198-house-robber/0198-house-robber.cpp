class Solution {
public:
    int t[100];
    int solve(int i, vector<int>& nums){
        if(i >= nums.size()){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int right = nums[i] + solve(i + 2, nums);
        int left = solve(i + 1, nums);
        return t[i] = max(left, right);
    }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(0, nums);
    }
};