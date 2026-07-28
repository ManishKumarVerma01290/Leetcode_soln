class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0, n = s.length(), Min = INT_MAX, Start = 0;
        unordered_map<char,int> freq;
        for (auto c : t){
            freq[c]++;
        }
        int count = freq.size();
        while (j < n){
            if (freq.find(s[j]) != freq.end()){
                freq[s[j]]--;
                if (freq[s[j]] == 0){
                    count--;
                }
            }
            if (count == 0){
                while (count == 0){
                    if (j - i + 1 < Min){
                        Min = j - i + 1;
                        Start = i;
                    }
                    if (freq.find(s[i]) != freq.end()){
                        freq[s[i]]++;
                        if (freq[s[i]] > 0){
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if (Min == INT_MAX){
            return "";
        }
        return s.substr(Start, Min);
    }
};
