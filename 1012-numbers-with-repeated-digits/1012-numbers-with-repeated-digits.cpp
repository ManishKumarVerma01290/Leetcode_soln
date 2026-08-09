class Solution {
public:
    using ll = long long;
    ll dp[2][1024][11][2];
    ll dp_fxn(string &s, bool tight, ll mask, ll idx, bool lz){
        if(idx == s.size()){
            return 1;
        }
        if(dp[tight][mask][idx][lz] != -1){
            return dp[tight][mask][idx][lz];
        }
        ll lb = 0, ub = 9;
        if(tight == true){
            ub = s[idx] - '0';
        }
        ll ans = 0;
        for(ll i = lb; i <= ub; i++){
            bool ntight = tight && (i == ub);
            bool nlz = lz && (i == 0);
            if(i == 0 && lz == true){
                ll nmask = mask;
                ans += dp_fxn(s, ntight, nmask, idx + 1, nlz);
            }
            else{
                if(mask & (1 << i)){
                    continue;
                }
                ll nmask = mask | (1 << i);
                ans += dp_fxn(s, ntight, nmask, idx + 1, nlz);
            }
        }
        return dp[tight][mask][idx][lz] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        ll ans = dp_fxn(s, true, 0, 0, true);
        return n - ans + 1;
    }
};