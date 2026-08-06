class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;    
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int dis = temp.first;
            int r = temp.second.first;
            int c = temp.second.second;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int val = max(dis, abs(heights[r][c] - heights[nr][nc]));
                    if(dist[nr][nc] > val){
                        dist[nr][nc] = val;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};