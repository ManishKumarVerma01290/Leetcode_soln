class Solution {
public:
    using ll = long long;
    const int MOD = (int)(1e9 + 7);
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i : roads){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<ll> dist(n, LLONG_MAX), ways(n, 0);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto temp = pq.top();
            ll dis = temp.first;
            int node = temp.second;
            pq.pop();
            if(dist[node] < dis){
                continue;
            }
            for(auto ni : adj[node]){
                int nnode = ni.first;
                int nwt = ni.second;
                if(dist[nnode] > dis + nwt){
                    dist[nnode] = dis + nwt;
                    ways[nnode] = ways[node];
                    pq.push({dist[nnode], nnode});
                }
                else if(dist[nnode] == dis + nwt){
                    ways[nnode] = (ways[nnode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};