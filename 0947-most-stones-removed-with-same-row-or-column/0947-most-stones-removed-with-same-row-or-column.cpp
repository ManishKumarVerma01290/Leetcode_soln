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

    int removeStones(vector<vector<int>>& stones) {
        int R = 0, C = 0;
        for(auto i : stones){
            R = max(R, i[0]);
            C = max(C, i[1]);
        }
        size.resize(R + C + 2, 1);
        parent.resize(R + C + 2);
        for(int i = 0; i < (R + C + 2); i++){
            parent[i] = i;
        }
        unordered_map<int, int> unique_node;
        for(auto i : stones){
            int r = i[0];
            int c = i[1] + R + 1;
            union_do(r, c);
            unique_node[r] = 1;
            unique_node[c] = 1;
        }
        int count = 0;
        for(auto i : unique_node){
            if(find_parent(i.first) == i.first){
                count++;
            }
        }
        return stones.size() - count;
    }
};
