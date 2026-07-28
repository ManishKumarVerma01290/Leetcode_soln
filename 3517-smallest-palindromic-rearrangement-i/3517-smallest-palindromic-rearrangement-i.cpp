class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n/2; i++){
            ans += s[i];
        }
        string temp = "";
        sort(ans.begin(), ans.end());
        if(ans.size()* 2 < s.size()){
            ans += s[n/2];
            temp = ans;
        }
        else{
            temp = ans;
        } 
        for(int i = n/2 - 1; i >= 0; i--){
            ans += temp[i];
        }
        return ans;
    }
};