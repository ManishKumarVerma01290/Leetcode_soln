class Solution {
public:
    vector<int> size;
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
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int p = n * n;
        size.resize(p, 1);
        parent.resize(p);
        for(int i = 0; i < p; i++){
            parent[i] = i;
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 0){
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if(grid[nr][nc] == 1){
                            int node = r * n + c;
                            int nnode = nr * n + nc;
                            union_do(node, nnode);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 1){
                    continue;
                }
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> temp;
                for(int k = 0; k < 4; k++){
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                        if(grid[nr][nc] == 1){
                            int nnode = nr * n + nc;
                            temp.insert(find_parent(nnode));
                        }
                    }
                }
                int val = 1;
                for(auto i : temp){
                    val += size[i];
                }
                ans = max(ans, val);
            }
        }
        for(int i = 0; i < n * n; i++){
            ans = max(ans, size[find_parent(i)]);
        }
        return ans;
    }
};