class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find_parent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find_parent(parent[node]);
    }
    void union_do(int u, int v){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv){
            return;
        }
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){
        int v = isConnected.size();
        rank.resize(v, 0);
        parent.resize(v);
        for(int i = 0; i < v; i++){
            parent[i] = i;
        }
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j] == 1){
                    union_do(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < v; i++){
            if(find_parent(i) == i){
                ans++;
            }
        }
        return ans;
        
    }
};