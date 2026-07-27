class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& image, int color, int old, int dr[], int dc[]){
        vis[i][j] = color;
        int n = image.size();
        int m = image[0].size();
        for(int k = 0; k < 4; k++){
            int ni = i + dr[k];
            int nj = j + dc[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && vis[ni][nj] != color && image[ni][nj] == old){
                vis[ni][nj] = color;
                dfs(ni, nj, vis, image, color, old, dr, dc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis = image;
        int old = image[sr][sc];
        if(old == color){
            return image;
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        dfs(sr, sc, vis, image, color, old, dr, dc);
        return vis;
    }
};