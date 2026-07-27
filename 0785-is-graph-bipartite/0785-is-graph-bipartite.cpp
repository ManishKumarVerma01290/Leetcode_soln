class Solution {
public:
    bool solve(int i, vector<int>& cvis, vector<vector<int>>& graph){
        int n = graph.size();
        if(cvis[i] == -1){
            cvis[i] = 1;
        //     if(!solve(i, cvis, graph))
        //         return false;
        }
        for(auto temp : graph[i]){
            if(cvis[temp] == -1 && cvis[i] == 1){
                cvis[temp] = 2;
                if(!solve(temp, cvis, graph)){
                    return false;
                }
                
            }
            else if(cvis[temp] == -1 && cvis[i] == 2){
                cvis[temp] = 1;
                if(!solve(temp, cvis, graph)){
                    return false;
                }
            }
            else if(cvis[temp] != -1 && cvis[i] == cvis[temp]){
                return false;
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