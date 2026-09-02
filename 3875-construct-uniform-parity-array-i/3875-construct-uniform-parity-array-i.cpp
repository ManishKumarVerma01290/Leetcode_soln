class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> ans(n);
        int l = 0, r = n - 1;
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                ans[r--] = nums1[i];
            }
            else{
                ans[l++] = nums1[i];
            }
        }
        int odd = l;
        int even = n - r - 1;
        if(odd == 0 || even == 0){
            return true;
        }
        if(odd == 1 || even == 1){
            return true;
        }
        if(even > odd && odd != 1){
            // change into even 
            for(int i = 0; i < odd - 1; i++){
                ans[i] = nums1[i] - nums1[i + 1];
            }
            ans[odd - 1] = nums1[odd - 1] - nums1[0];
            return true;
        }
        else{
            // change into odd 
            for(int i = odd; i < n; i++){
                ans[i] = nums1[i] - nums1[0];
            }
            return true;
        }
        return false;
    }
};