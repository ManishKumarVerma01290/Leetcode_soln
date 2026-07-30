class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto temp : times){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            pair<int, int> temp = pq.top();
            pq.pop();
            int dis = temp.first;
            int node = temp.second;
            if(dis > dist[node]){
                continue;
            }
            for(auto ni : adj[node]){
                int nv = ni.first;
                int nwt = ni.second;
                if(dis + nwt < dist[nv]){
                    dist[nv] = dis + nwt;
                    pq.push({dist[nv], nv});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};