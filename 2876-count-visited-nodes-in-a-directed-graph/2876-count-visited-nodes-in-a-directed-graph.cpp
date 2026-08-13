class Solution {
public:
    void solve(int i, vector<int>& vis, vector<vector<int>>& adj, vector<int>& ans) {
        vis[i] = 1;
        for(auto ni : adj[i]) {
            if(!vis[ni]) {
                solve(ni, vis, adj, ans);
            }
            else if(vis[ni] == 1){
                int cycleSize = 1;
                int x = ni;
                while(x != i) {
                    x = adj[x][0];
                    cycleSize++;
                }
                x = ni;
                while(true) {
                    ans[x] = cycleSize;
                    x = adj[x][0];
                    if(x == ni){
                        break;
                    }
                }
            }
        }
        for(auto ni : adj[i]){
            if(ans[i] == 0){
                ans[i] = 1 + ans[ni];
            }
        }
        vis[i] = 2;
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            adj[i].push_back(edges[i]);
        }
        vector<int> vis(n, 0);
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) {
                solve(i, vis, adj, ans);
            }
        }
        return ans;
    }
};