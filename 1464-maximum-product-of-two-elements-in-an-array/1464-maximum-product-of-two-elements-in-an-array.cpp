class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n =  nums.size();
        int Max = 0, SMax = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > Max){
                SMax = Max;
                Max = nums[i];
            }
            else{
                if(nums[i] > SMax){
                    SMax = nums[i];
                }
            }
        }
        return (Max - 1)*(SMax - 1);
    }
};