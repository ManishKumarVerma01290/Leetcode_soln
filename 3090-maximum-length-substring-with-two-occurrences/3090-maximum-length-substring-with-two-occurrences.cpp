class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int i = 0, j = 0;
        int n = s.length();
        int Max = 0;
        while(j < n) {
            freq[s[j]]++;
            if(freq[s[j]] > 2) {
                while(freq[s[j]] > 2) {
                    freq[s[i]]--;
                    i++;
                }
                Max = max(Max, j - i + 1);
                j++;
            }
            else {
                Max = max(Max, j - i + 1);
                j++;
            }
        }
        return Max;
    }
};