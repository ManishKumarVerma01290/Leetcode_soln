class Solution {
public:
    int t[46];
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        t[1] = 1;
        t[2] = 2;
        for(int i = 3; i < 46; i++){
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
};