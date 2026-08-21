class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0;
        int b = a, c = a, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                a++;
            }
            else if(nums[i] == 1){
                b++;
            }
            else if(nums[i] == 2){
                c++;
            }
        }
        for(int i = 0; i < n; i++){
            if(a > 0){
                nums[i] = 0;
                a--;
                continue;
            }
            if(b > 0){
                nums[i] = 1;
                b--;
                continue;
            }
            if(c > 0){
                nums[i] = 2;
                c--;
                continue;
            }
        }
    }
};