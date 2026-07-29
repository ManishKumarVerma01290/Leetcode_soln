class Solution {
public:
    bool dfs_cycle(int i, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto ni : adj[i]){
            if(!vis[ni]){
                if(dfs_cycle(ni, vis, pathvis, adj)){
                    return true;
                }
            }
            else if(pathvis[ni]){
                return true;
            }
        }
        pathvis[i] = 0;
        return false;
    }
    void solve(int i, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
        vis[i] = 1;
        for(auto ni : adj[i]){
            if(!vis[ni]){
                solve(ni, vis, adj, st);
            }
        }
        st.push(i);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto i : prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(dfs_cycle(i, vis, pathvis, adj)){
                    return false;
                }
            }
        }
        for(int i = 0; i < vis.size(); i++){
            vis[i] = 0;
        }
        stack<int> st;
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                solve(i, vis, adj, st);
            }
        }
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        for(auto ch : prerequisites){
            int i = ch[1];
            int j = ch[0];
            int l = 0, h = temp.size() - 1;
            while(l < h){
                if(temp[l] == i && temp[h] == j && l >= h){
                    return false;
                }
                l++;
                h--;
            }
        }
        return true;
    }
};