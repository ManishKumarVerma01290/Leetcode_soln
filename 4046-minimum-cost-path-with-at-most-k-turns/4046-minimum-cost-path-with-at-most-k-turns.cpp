class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        using temp = pair<int, pair<int, pair<int, pair<int, int>>>>;
        priority_queue<temp, vector<temp>, greater<temp>> pq;
        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(4, vector<int>(k + 1, 1e9))));
        pq.push({grid[0][0], {0, {0, {-1, 0}}}});
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int node = temp.first;
            int r = temp.second.first;
            int c = temp.second.second.first;
            int dir = temp.second.second.second.first;
            int turn = temp.second.second.second.second;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            if (r == m - 1 && c == n - 1) {
                return node;
            }
            if (dir != -1 && node > dist[r][c][dir][turn]) {
                continue;
            }
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int nturn = turn;

                    if (dir != -1 && dir != d) {
                        nturn++;
                    }

                    if (nturn <= k) {
                        int nnode = node + grid[nr][nc];

                        if (nnode < dist[nr][nc][d][nturn]) {
                            dist[nr][nc][d][nturn] = nnode;
                            pq.push({nnode, {nr, {nc, {d, nturn}}}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};