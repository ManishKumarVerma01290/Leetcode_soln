class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(int i = 0; i < n; i++){
            for(auto ni : graph[i]){
                adj[ni].push_back(i);
            }
        }
        for(int i = 0; i < n; i++){
            for(auto ni : adj[i]){
                indegree[ni]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto ni : adj[node]){
                indegree[ni]--;
                if(indegree[ni] == 0){
                    q.push(ni);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};