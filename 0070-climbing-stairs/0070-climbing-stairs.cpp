class Solution {
public:
    int t[46];
    int solve(int n){
        t[1] = 1;
        t[2] = 2;
        for(int i = 3; i <= n; i++){
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
    int climbStairs(int n) {
        return solve(n);
    }
};