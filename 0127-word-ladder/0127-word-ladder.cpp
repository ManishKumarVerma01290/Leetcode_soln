class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> temp(wordList.begin(), wordList.end());
        temp.erase(beginWord);
        while(!q.empty()){
            string nw = q.front().first;
            int count = q.front().second;
            q.pop();
            if(nw == endWord){
                return count;
            }
            for(int i = 0; i < nw.length(); i++){
                char val = nw[i];
                for(char k = 'a'; k <= 'z'; k++){
                    nw[i] = k;
                    if(temp.find(nw) != temp.end()){
                        temp.erase(nw);
                        q.push({nw, count + 1});
                    }
                }
                nw[i] = val;
            }
        }
        return 0;
    }
};