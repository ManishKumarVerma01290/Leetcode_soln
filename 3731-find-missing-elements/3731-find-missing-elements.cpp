class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size()-1; i++){
            int k = nums[i] + 1;
            while(k != nums[i+1]){
                ans.push_back(k);
                k++;
            }
        }
        return ans;
    }
};