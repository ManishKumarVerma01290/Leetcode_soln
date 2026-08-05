class Solution {
public:
    void solve(int i, vector<int>& vis, vector<vector<int>>& adj){
        vis[i] = 1;
        for(auto ni : adj[i]){
            if(!vis[ni]){
                vis[ni] = 1;
                solve(ni, vis, adj);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto i : invocations){
            adj[i[0]].push_back(i[1]);
        }
        if(!vis[k]){
            solve(k, vis, adj);
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                for(auto ni : adj[i]){
                    if(vis[ni] == 1){
                        vector<int> ans;
                        for(int j = 0; j < n; j++){
                            ans.push_back(j);
                        }
                        return ans;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};