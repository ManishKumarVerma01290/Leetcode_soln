class Solution {
public:
    using ll = long long;
    ll dp[2][12][12];
    ll dp_fxn(string &s, bool tight, ll idx, ll count) {
        if(idx == s.size()) {
            return dp[tight][idx][count] = count;
        }
        if(dp[tight][idx][count] != -1) {
            return dp[tight][idx][count];
        }
        ll lb = 0;
        ll ub = 9;
        if(tight == true) {
            ub = s[idx] - '0';
        }
        ll ans = 0;
        for(ll i = lb; i <= ub; i++) {
            ll ncount = count;
            if(i == 1) {
                ncount++;
            }
            bool ntight = tight && (i == ub);
            ans += dp_fxn(s, ntight, idx + 1, ncount);
        }
        return dp[tight][idx][count] = ans;
    }

    int countDigitOne(int n) {
        string a = to_string(n);
        memset(dp, -1, sizeof(dp));
        ll ans = dp_fxn(a, true, 0, 0);
        return ans;
    }
};