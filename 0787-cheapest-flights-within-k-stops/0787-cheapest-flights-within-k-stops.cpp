class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int, int>>> adj(n);
        vector<int> dist(n, 1e9);
        for(auto i : flights){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[src] = 0;
        pq.push({0, {src, 0}});
        int count = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            int dis = temp.first;
            int node = temp.second.first;
            int stop = temp.second.second;
            pq.pop();
            if(stop > k){
                continue;
            }
            for(auto ni : adj[node]){
                int nnode = ni.first;
                int nwt = ni.second;
                if(dist[nnode] > dis + nwt){
                    dist[nnode] = dis + nwt;
                    pq.push({dist[nnode], {nnode, stop + 1}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};