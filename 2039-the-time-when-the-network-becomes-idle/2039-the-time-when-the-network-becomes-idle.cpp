class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<pair<int, int>>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back({i[1], 1});
            adj[i[1]].push_back({i[0], 1});
        }
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            pair<int, int> temp = pq.top();
            pq.pop();
            int dis = temp.first;
            int node = temp.second;
            if(dis > dist[node]){
                continue;
            }
            for(auto ni : adj[node]){
                int nnode = ni.first;
                int nwt = ni.second;
                if(dis + nwt < dist[nnode]){
                    dist[nnode] = dis + nwt;
                    pq.push({dist[nnode], nnode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            int x = (dist[i]*2 - 1)/patience[i];
            int lto = x * patience[i];
            int lti = lto + dist[i]*2;
            ans = max(ans, lti);
        }
        return ans+1;
    }
};