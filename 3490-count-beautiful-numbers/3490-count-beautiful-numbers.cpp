class Solution {
public:
    using ll = long long;
    ll dp[2][11][91][91];
    ll dp_fxn(string &s, bool tight, ll idx, ll sum, ll prod, ll targetsum){
        if(idx == (ll)s.size()){
            return (sum == targetsum && prod == 0);
        }
        if(dp[tight][idx][sum][prod] != -1){
            return dp[tight][idx][sum][prod];
        }
        ll lb = 0;
        ll ub = 9;
        if(tight){
            ub = s[idx] - '0';
        }
        ll ans = 0;
        for(ll i = lb; i <= ub; i++){
            ll nsum = sum + i;
            if(nsum > targetsum){
                break; 
            }
            ll base = 0;
            if(sum != 0){ 
                base = prod;  
            }
            else {          
                base = 1;
            }
            ll nprod = (base * i) % targetsum; 
            bool ntight = tight && (i == ub);
            ans += dp_fxn(s, ntight, idx + 1, nsum, nprod, targetsum);
        }
        return dp[tight][idx][sum][prod] = ans;
    }
    ll solve(string s){
        ll ans = 0;
        ll maxDigSum = 9 * (ll)s.size();
        for(int targetsum = 1; targetsum <= maxDigSum; targetsum++){
            memset(dp, -1, sizeof(dp));
            ans += dp_fxn(s, 1, 0, 0, 0, targetsum);
        }
        return ans;
    }
    int beautifulNumbers(int l, int r) {
        string a = to_string(l - 1);
        string b = to_string(r);
        return solve(b) - solve(a);
    }
};