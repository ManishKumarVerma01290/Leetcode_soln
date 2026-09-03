class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> ans(n);
        int l = 0, r = n - 1;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                ans[r--] = nums1[i];
            }
            else{
                ans[l++] = nums1[i];
                mn = min(mn, nums1[i]);  
            }
        }
        int odd = l;
        int even = n - r - 1;
        if(odd == 0 || even == 0){
            return true;
        }
        for(int i = odd; i < n; i++){
            if(ans[i] < mn){
                return false;
            }
        }
        return true;
    }
};