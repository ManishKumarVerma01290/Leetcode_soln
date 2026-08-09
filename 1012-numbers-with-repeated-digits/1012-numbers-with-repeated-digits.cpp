class Solution {
public:
    using ll = long long;

    ll dp_fxn(string &s, bool tight, ll mask, ll idx, bool lz){
        if(idx == s.size()){
            return 1;
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
        return ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        ll ans = dp_fxn(s, true, 0, 0, true);
        return n - ans + 1;
    }
};