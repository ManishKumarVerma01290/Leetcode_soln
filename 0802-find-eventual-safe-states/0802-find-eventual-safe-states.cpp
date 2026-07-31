class Solution {
public:
    bool check_cycle(int i, vector<int>& vis, vector<vector<int>>& graph, vector<int>& pathvis, vector<int>& temp){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto ni : graph[i]){
            if(!vis[ni]){
                if(check_cycle(ni, vis, graph, pathvis, temp)){
                    return true;
                }
            }
            else if(pathvis[ni]){
                return true;
            }
        }
        temp[i] = 1;
        pathvis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> temp(n, 0);
        vector<int> safe;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                check_cycle(i, vis, graph, pathvis, temp);
            }
        }
        for(int i = 0; i < n; i++){
            if(temp[i] == 1){
                safe.push_back(i);
            }
        }
        return safe;
    }
};