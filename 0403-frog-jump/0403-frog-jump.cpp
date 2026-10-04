class Solution {
public:
    int t[2001][2001];
    bool solve(int i, vector<int>& stones, int n, int k){
        if(i == n - 1){
            return true;
        }
        if(t[i][k] != -1){
            return t[i][k];
        }
        for(int j = k - 1; j <= k + 1; j++){
            int temp = stones[i] + j;
            for(int p = i + 1; p < n; p++){
                if(stones[p] == temp){
                    if(solve(p, stones, n, j)){
                        return true;
                    }
                }
            }
        }
        return t[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 1){
            return true;
        }
        if(stones[1] != 1){
            return false;
        }
        memset(t, -1, sizeof(t));
        return solve(1, stones, n, 1);
    }
};