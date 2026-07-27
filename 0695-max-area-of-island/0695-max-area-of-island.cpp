class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int dr[], int dc[], int& count){
        vis[i][j] = 1;
        count++;
        int n = grid.size();
        int m = grid[0].size();
        for(int k = 0; k < 4; k++){
            int ni = i + dr[k];
            int nj = j + dc[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && grid[ni][nj] == 1){
                vis[ni][nj] = 1;
                dfs(ni, nj, vis, grid, dr, dc, count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int count, ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    count = 0;
                    dfs(i, j, vis, grid, dr, dc, count);
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};