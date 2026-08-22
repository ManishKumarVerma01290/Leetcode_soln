class Solution {
public:
    bool solve(string a, int m){
        int n = a.size();
        int sum = 0, prod = 1;
        for(int i = 0; i < n; i++){
            sum += a[i] - '0';
            prod *= a[i] - '0';
        }
        bool ans = false;
        if(m % (sum + prod) == 0){
            ans = true;
        }
        return ans;
    }
    bool checkDivisibility(int n) {
        string a = to_string(n);
        return solve(a, n);
    }
};