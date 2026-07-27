class Solution {
public:
    bool solve(int i, vector<int>& cvis, vector<vector<int>>& graph){
        int n = graph.size();
        queue<int> q;
        cvis[i] = 1;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto temp : graph[node]){
                if(cvis[temp] == -1 && cvis[node] == 1){
                    cvis[temp] = 2;
                    q.push(temp);
                }
                else if(cvis[temp] == -1 && cvis[node] == 2){
                    cvis[temp] = 1;
                    q.push(temp);
                }
                else if(cvis[temp] != -1 && cvis[node] == cvis[temp]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cvis(n, -1);
        for(int i = 0; i < n; i++){
            if(cvis[i] == -1){
                if(!solve(i, cvis, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};