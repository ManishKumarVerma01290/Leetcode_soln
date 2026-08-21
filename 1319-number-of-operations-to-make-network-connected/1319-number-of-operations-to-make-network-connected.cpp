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
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        int count = 0;
        for(auto i : connections){
            int u = i[0];
            int v = i[1];
            if(find_parent(u) == find_parent(v)){
                count++;
            }
            else{
                union_do(u, v);
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++){
            if(find_parent(i) == i){
                val++;
            }
        }
        if(count >= val - 1){
            return val - 1;
        }
        return -1;
    }
};