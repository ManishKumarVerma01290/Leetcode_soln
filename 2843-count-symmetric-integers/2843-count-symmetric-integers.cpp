class Solution {
public:
    int dp_fxn(string s, bool tight, int idx, int sum_a, int sum_b){
        if(idx == s.size()){
            return sum_a == sum_b;
        }
        int n = s.size();
        int lb = 0, ub = 9;
        if(tight){
            ub = s[idx] - '0';
        }
        int ans = 0;
        for(int i = lb; i <= ub; i++) {
            if(idx == 0 && i == 0){
                continue;
            }
            int nsum_a = sum_a;
            int nsum_b = sum_b;
            if(idx < n / 2){
                nsum_a += i;
            }
            else{
                nsum_b += i;
            }
            bool ntight = tight && (i == ub);
            ans += dp_fxn(s, ntight, idx + 1, nsum_a, nsum_b);
        }
        return ans;
    }

    int count(int x) {
        string s = to_string(x);
        int ans = 0;
        for(int len = 2; len <= s.size(); len += 2) {
            string t;
            if(len == s.size()){
                t = s;
            }
            else{
                t = string(len, '9');
            }
            ans += dp_fxn(t, 1, 0, 0, 0);
        }
        return ans;
    }

    int countSymmetricIntegers(int low, int high) {
        return count(high) - count(low - 1);
    }
};