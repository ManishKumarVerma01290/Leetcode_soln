class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> freq;

        for(auto i : s) {
            freq[i]++;
        }

        vector<int> num;
        for(auto i : s) {
            num.push_back(i - 'a');
        }

        sort(num.begin(), num.end());

        int Min = num[0], Max = num[num.size() - 1];

        // Case 1: smallest permutation itself is greater
        if(Min > target[0] - 'a') {
            string ans = "";

            for(auto i : num) {
                ans += char(i + 'a');
            }

            return ans;
        }

        // TERA LOGIC
        string ans = "";

        for(int i = 0; i < target.size(); i++) {

            // Same character mil gaya
            if(freq.find(target[i]) != freq.end()) {

                ans += target[i];

                freq[target[i]]--;

                if(freq[target[i]] == 0) {
                    freq.erase(target[i]);
                }
            }

            // Same character nahi mila
            else {

                // target[i] se bada smallest character
                auto it = freq.upper_bound(target[i]);

                if(it != freq.end()) {

                    ans += it->first;

                    it->second--;

                    if(it->second == 0) {
                        freq.erase(it);
                    }

                    // Remaining smallest
                    while(!freq.empty()) {
                        auto p = freq.begin();

                        ans += p->first;

                        p->second--;

                        if(p->second == 0) {
                            freq.erase(p);
                        }
                    }

                    return ans;
                }

                // yahan direct bigger nahi mila
                break;
            }
        }

        // 🔥 Yahan tak target match ho gaya ya aage answer nahi bana
        // Previous characters ko wapas lao aur upper_bound try karo

        for(int i = min((int)ans.size(), (int)target.size()) - 1;
            i >= 0; i--) {

            freq[ans[i]]++;

            ans.pop_back();

            auto it = freq.upper_bound(target[i]);

            if(it != freq.end()) {

                ans += it->first;

                it->second--;

                if(it->second == 0) {
                    freq.erase(it);
                }

                // Remaining smallest
                while(!freq.empty()) {

                    auto p = freq.begin();

                    ans += p->first;

                    p->second--;

                    if(p->second == 0) {
                        freq.erase(p);
                    }
                }

                return ans;
            }
        }
        return "";
    }
};