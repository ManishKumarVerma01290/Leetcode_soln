class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] == 1){
            return -1;
        }
        if(grid[n-1][n-1] == 1){
            return -1;
        }
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int dis = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            for(int dr = -1; dr <= 1; dr++){
                for(int dc = -1; dc <= 1; dc++){
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if(grid[nr][nc] == 0 && dist[nr][nc] > dist[r][c] + 1){
                            dist[nr][nc] = dist[r][c] + 1;
                            q.push({dist[nr][nc], {nr, nc}});
                        }
                    }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9){
            return -1;
        }
        return dist[n-1][n-1] + 1;
    }
};