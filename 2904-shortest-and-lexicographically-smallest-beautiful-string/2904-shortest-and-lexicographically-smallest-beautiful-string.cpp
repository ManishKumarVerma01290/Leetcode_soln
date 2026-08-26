class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        set<pair<int, int>> temp;
        int i = 0, j = 0, sum = 0;
        while(j < n) {
            sum += s[j] - '0';
            if(sum < k) {
                j++;
            }
            else if(sum == k) {
                while(i < j && s[i] == '0') {
                    i++;
                }
                temp.insert({i, j});
                j++;
            }
            else {
                while(sum > k) {
                    sum -= s[i] - '0';
                    i++;
                }
                if(sum == k) {
                    while(i < j && s[i] == '0') {
                        i++;
                    }
                    temp.insert({i, j});
                }
                j++;
            }
        }
        if(temp.empty()) {
            return "";
        }
        int diff = INT_MAX;
        int a = 0, b = 0;
        for(auto it : temp) {
            int l = it.first;
            int r = it.second;
            int len = r - l + 1;
            if(len < diff) {
                diff = len;
                a = l;
                b = r;
            }
            else if(len == diff) {
                string x = s.substr(l, len);
                string y = s.substr(a, diff);
                if(x < y) {
                    a = l;
                    b = r;
                }
            }
        }
        return s.substr(a, diff);
    }
};