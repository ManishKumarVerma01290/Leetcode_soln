class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        int ans = 1;
        for(int p = 0; p < n; p++) {
            sum += nums[p];
            while(1LL * nums[p] * (p - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, p - l + 1);
        }
        return ans;
    }
};