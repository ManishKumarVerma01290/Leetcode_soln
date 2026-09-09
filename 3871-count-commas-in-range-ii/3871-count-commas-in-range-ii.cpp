class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) {
            return 0;
        }
        long long ans = n - 1000 + 1;
        if(n < 1000000) {
            return ans;
        }
        ans += n - 1000000 + 1;
        if(n < 1000000000) {
            return ans;
        }
        ans += n - 1000000000 + 1;
        if(n < 1000000000000LL) {
            return ans;
        }
        ans += n - 1000000000000LL + 1;
        if(n < 1000000000000000LL) {
            return ans;
        }
        ans += n - 1000000000000000LL + 1;
        return ans;
    }
};