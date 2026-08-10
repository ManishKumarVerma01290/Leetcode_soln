class Solution {
public:
    int dp_fxn(string& s, int idx, bool tight, bool lz, int sum){
        if(idx == s.size()){
            return (sum % 2 == 0);
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
            bool nlz = lz && (i == 0);
            ans += dp_fxn(s, idx + 1, ntight, nlz, nsum);
        }
        return ans;
    }
    int countEven(int num) {
        string s = to_string(num);
        return dp_fxn(s, 0, 1, 1, 0) - 1;
    }
};