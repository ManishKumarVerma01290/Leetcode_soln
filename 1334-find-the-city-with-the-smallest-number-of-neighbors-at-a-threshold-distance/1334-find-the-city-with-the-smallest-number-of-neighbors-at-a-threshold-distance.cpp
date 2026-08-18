class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        for(auto i : edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[k][j] == INT_MAX || dist[i][k] == INT_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[k][j] + dist[i][k]);
                }
            }
        }
        int count = n;
        int val = 0;
        for(int i = 0; i < n; i++){
            int ans = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold){
                    ans++;
                }
            }
            if(ans <= count){
                count = ans;
                val = i;
            }
        }
        return val;
    }
};