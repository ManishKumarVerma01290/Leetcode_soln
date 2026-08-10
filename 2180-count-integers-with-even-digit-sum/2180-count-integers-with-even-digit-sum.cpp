class Solution {
public:
    int dp[5][2][40];
    int dp_fxn(string& s, int idx, bool tight, int sum){
        if(idx == s.size()){
            return (sum % 2 == 0);
        }
        if(dp[idx][tight][sum] != -1){
            return dp[idx][tight][sum];
        }
        int lb = 0;
        int ub = 9;
        if(tight){
            ub = s[idx] - '0';
        }
        int ans = 0;
        for(int i = lb; i <= ub; i++){
            int nsum = sum + i;
            bool ntight = tight && (i == ub);
            ans += dp_fxn(s, idx + 1, ntight, nsum);
        }
        return dp[idx][tight][sum] = ans;
    }
    int countEven(int num) {
        string s = to_string(num);
        memset(dp, -1, sizeof(dp));
        return dp_fxn(s, 0, 1, 0) - 1;
    }
};