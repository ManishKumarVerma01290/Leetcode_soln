class Solution {
public:
    int t[202][202];
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                t[i][j] = INT_MAX;
            }
        }
        t[m][n-1] = 1;
        t[m-1][n] = 1;

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int h = min(t[i+1][j], t[i][j+1]);
                t[i][j] = max(1, h - dungeon[i][j]);
            }
        }

        return t[0][0];
    }
};