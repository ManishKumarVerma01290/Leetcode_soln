class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto i : times){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1, INT_MAX);
        set<pair<int, int>> st;
        dist[k] = 0;
        st.insert({0, k});
        while(!st.empty()){
            pair<int, int> temp = *(st.begin());
            st.erase(temp);
            int dis = temp.first;
            int node = temp.second;
            // if(dis > dist[node]){
            //     continue;
            // }
            for(auto ni : adj[node]){
                int nnode = ni.first;
                int nwt = ni.second;
                if(nwt + dis < dist[nnode]){
                    if(dist[nnode] != INT_MAX){
                        st.erase({dist[nnode], nnode});
                    }
                    dist[nnode] = nwt + dis;
                    st.insert({dist[nnode], nnode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
                return dist[i];
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};