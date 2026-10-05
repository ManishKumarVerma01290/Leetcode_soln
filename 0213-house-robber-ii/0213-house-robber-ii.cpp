class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = nums[0];
        if(n == 1){
            return prev2;
        }
        int prev = max(nums[0], nums[1]);
        if(n == 2){
            return prev;
        }
        for(int i = 2; i < n - 1; i++){
            int take = 0, ntake = 0;
            take += nums[i] + prev2;
            ntake += prev;
            int curr = max(take, ntake);
            prev2 = prev;
            prev = curr;
        }
        int sum = 0;
        sum = max(sum, prev);
        
        prev2 = nums[1];
        prev = max(nums[1], nums[2]);
        if(n == 3){
            return max(prev, nums[0]);
        }
        for(int i = 3; i < n; i++){
            int take = 0, ntake = 0;
            take += nums[i] + prev2;
            ntake += prev;
            int curr = max(take, ntake);
            prev2 = prev;
            prev = curr;
        }
        sum = max(sum, prev);
        return sum;
    }
};