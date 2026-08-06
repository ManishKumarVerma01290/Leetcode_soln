class Solution {
public:
    int solve(int n){
        int a, b;
        a = n % 10;
        n = n / 10;
        if(n == 0){
            return a;
        }
        b = n;
        return a * b;
    }
    int smallestNumber(int n, int t) {
        int i = n;
        while(i <= 100){
            if(!(solve(i) % t)){
                return i;
            }
            i++;
        }
        return -1;
    }
};