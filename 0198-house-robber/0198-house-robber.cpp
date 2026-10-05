class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        for(int idx = 2; idx < n; idx++){
            int take = nums[idx] + prev2;
            int ntake = prev;
            int curr = max(take, ntake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};