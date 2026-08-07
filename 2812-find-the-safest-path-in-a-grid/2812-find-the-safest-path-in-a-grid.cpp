class Solution {
public:
    bool check(vector<vector<int>>& dist, int val, vector<vector<int>>& vis){
        int n = dist.size();
        if(dist[0][0] < val){
            return false;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int r = temp.first;
            int c = temp.second;
            if(r == n-1 && c == n-1){
                return true;
            }
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    if(!vis[nr][nc] && dist[nr][nc] >= val){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid){
        int n = grid.size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({dist[i][j], {i, j}});
                }
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int dis = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    if(dist[nr][nc] == -1 || dist[nr][nc] > dis + 1){
                        dist[nr][nc] = dis + 1;
                        q.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        int l = 0, h = 0, ans = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                h = max(h, dist[i][j]);
            }
        }
        while(l <= h){
            int mid = l + (h - l)/2;
            vector<vector<int>> vis(n, vector<int> (n, 0));
            if(check(dist, mid, vis)){
                ans = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return ans;
    }
};