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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        parent.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    union_do(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> list(n);
        for(auto i : mp){
            string s = i.first;
            int val = find_parent(i.second);
            list[val].push_back(s);

        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(list[i].size() == 0){
                continue;
            }
            sort(list[i].begin(), list[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto j : list[i]){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};