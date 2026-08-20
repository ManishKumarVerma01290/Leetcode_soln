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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        vector<pair<int, pair<int, int>>> weight;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                weight.push_back({wt, {i, j}});
            }
        }
        int ans = 0;
        sort(weight.begin(), weight.end());
        for(auto i : weight){
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            if(find_parent(u) != find_parent(v)){
                ans += wt;
                union_do(u, v);
            }
        }
        return ans;
    }
};