class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> dist(n, -1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto ni : adj[node]){
                if(dist[ni] == -1){
                    dist[ni] = dist[node] + 1;
                    q.push(ni);
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