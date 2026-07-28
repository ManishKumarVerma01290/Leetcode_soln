class Solution {
public:
    void rotate(string& s){
        char temp = s[s.size() - 1];
        s.erase(s.size() - 1, 1);
        s.insert(s.begin(), temp);
    }
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.length(); i++){
            rotate(s);
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};