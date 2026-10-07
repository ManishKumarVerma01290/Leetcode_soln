class Solution { 
public: 
    vector<int> solve(int idx, int n, int val, vector<int>& ans){ 
        if(idx > n){ 
            return ans; 
        }
        ans[idx] = 1; 
        idx++; 
        while(pow(2, val) - 1 > idx && idx < n){ 
            ans[idx] = ans[idx - pow(2, val - 1)] + 1; 
            idx++; 
        } 
        if(idx <= n){
            ans[idx] = ans[idx - pow(2, val - 1)] + 1; 
        }
        return solve(idx + 1, n, val + 1, ans); 
    } 

    vector<int> countBits(int n) { 
        vector<int> ans(n + 1, 0); 
        if(n == 0){ 
            return {0}; 
        } 
        if(n == 1){ 
            return {0, 1}; 
        } 
        ans[1] = 1;
        return solve(2, n, 2, ans); 
    } 
};