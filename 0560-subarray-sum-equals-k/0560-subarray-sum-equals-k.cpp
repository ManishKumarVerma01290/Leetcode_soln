class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        int sum = 0, count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        while(j < n){
            sum += nums[j];
            if(mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }
            mp[sum]++;
            j++;
        }
        return count;
    }
};