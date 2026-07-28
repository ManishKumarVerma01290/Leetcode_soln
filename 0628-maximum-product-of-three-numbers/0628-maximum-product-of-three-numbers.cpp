class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int Max = INT_MIN;
        int SMax = Max, TMax = Max;
        int Min = INT_MAX;
        int SMin = Min;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > Max){
                TMax = SMax;
                SMax = Max;
                Max = nums[i];
            }
            else if(nums[i] > SMax){
                TMax = SMax;
                SMax = nums[i];
            }
            else if(nums[i] > TMax){
                TMax = nums[i];
            }
            if(nums[i] < Min){
                SMin = Min;
                Min = nums[i];
            }
            else if(nums[i] < SMin){
                SMin = nums[i];
            }
        } 
        return max(Max * SMax * TMax, Max * SMin * Min);
    }
};