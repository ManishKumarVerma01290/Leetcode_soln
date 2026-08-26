class Solution {
public:
int t[1001];
    int solve(vector<int>& cost, int i) {
        if(i >= cost.size()) {
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int ans = cost[i] + min(solve(cost, i + 1), solve(cost, i + 2));
        return t[i] = ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        int ans = min(solve(cost, 0), solve(cost, 1));
        return ans;
    }
};