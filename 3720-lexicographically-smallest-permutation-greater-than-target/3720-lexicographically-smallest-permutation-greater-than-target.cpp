class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> freq;
        for (auto i : s) {
            freq[i]++;
        }
        vector<int> num;
        for (auto i : s) {
            num.push_back(i - 'a');
        }
        sort(num.begin(), num.end());
        int Min = num[0], Max = num[num.size() - 1];
        if (Min > target[0] - 'a') {
            string ans = "";
            for (auto i : num) {
                ans += char(i + 'a');
            }
            return ans;
        }
        string ans = "";
        for (int i = 0; i < target.size(); i++) {
            if (freq.find(target[i]) != freq.end()) {
                ans += target[i];
                freq[target[i]]--;
                if (freq[target[i]] == 0) {
                    freq.erase(target[i]);
                }
            } else {
                auto it = freq.upper_bound(target[i]);
                if (it != freq.end()) {
                    ans += it->first;
                    it->second--;
                    if (it->second == 0) {
                        freq.erase(it);
                    }
                    while (!freq.empty()) {
                        auto p = freq.begin();
                        ans += p->first;
                        p->second--;
                        if (p->second == 0) {
                            freq.erase(p);
                        }
                    }
                    return ans;
                }
                break;
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            freq[ans[i]]++;
            ans.pop_back();
            auto it = freq.upper_bound(target[i]);
            if (it != freq.end()) {
                ans += it->first;
                freq[it->first]--;
                if (freq[it->first] == 0) {
                    freq.erase(it->first);
                }
                while (!freq.empty()) {
                    auto p = freq.begin();
                    ans += p->first;
                    p->second--;
                    if (p->second == 0) {
                        freq.erase(p);
                    }
                }
                return ans;
            }
        }
        return "";
    }
};