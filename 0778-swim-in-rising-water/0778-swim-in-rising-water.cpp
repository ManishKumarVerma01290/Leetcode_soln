class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dist(n * n, 1e9);
        dist[0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        int Max = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int node = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;
            if(i == n - 1 && j == n - 1){
                return node;
            }
            int di[] = {-1, 0, 1, 0};
            int dj[] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int ni = i + di[k];
                int nj = j + dj[k];
                if(ni >= 0 && ni < n && nj >= 0 && nj < n){
                    int Max = max(node, grid[ni][nj]);
                    int idx = ni * n + nj;
                    if (Max < dist[idx]){
                        dist[idx] = Max;
                        pq.push({Max, {ni, nj}});
                    }
                }
            }  
        }
        return -1;
    }
};