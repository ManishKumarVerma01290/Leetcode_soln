class Solution {
public:
    using ll = long long;
    ll dp[2][17][301][17][2];
    ll dp_fxn(string& s, bool tight, ll idx, ll diff, ll count, bool lz) {

        if(idx == s.size()) {
            if(count < 2) {
                return 0;
            }
            return (diff == 0);
        }
        if(dp[tight][idx][diff + 150][count][lz] != -1) {
            return dp[tight][idx][diff + 150][count][lz];
        }
        ll lb = 0;
        ll ub = 9;
        if(tight){
            ub = s[idx] - '0';
        }
        ll ans = 0;
        for(ll i = lb; i <= ub; i++) {
            ll ndiff = diff;
            ll ncount = count;
            bool nlz = lz && (i == 0);
            if(!nlz){
                ncount++;
                if(ncount % 2 == 1) {
                    ndiff += i;       
                }
                else {
                    ndiff -= i;     
                }
            }
            bool ntight = tight && (i == ub);
            ans += dp_fxn(s, ntight, idx + 1, ndiff, ncount, nlz);
        }
        return dp[tight][idx][diff + 150][count][lz] = ans;
    }
    long long countBalanced(long long low, long long high) {
        string a = to_string(low - 1);
        string b = to_string(high);
        memset(dp, -1, sizeof(dp));
        ll left = dp_fxn(a, true, 0, 0, 0, true);
        memset(dp, -1, sizeof(dp));
        ll right = dp_fxn(b, true, 0, 0, 0, true);
        return right - left;
    }
};