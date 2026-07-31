class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int k = 1;
        int freq[26] = {0};
        for(auto c : word){
            freq[c - 'a']++;
        }
        sort(freq, freq + 26, greater<int>());
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0){
                break;
            }
            if(i > 0 && i % 8 == 0){
                k++;
            }
            ans += k * freq[i];
        }
        return ans;
    }
};