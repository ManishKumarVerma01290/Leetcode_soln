class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> freq;
        for(auto i : stones){
            freq[i] = {};
        }
        freq[0].insert(1);
        int lastStone = stones.back();
        for(int i = 0; i < stones.size(); i++){
            int currStone = stones[i];
            for(int k : freq[currStone]){
                int pos = currStone + k;
                if(pos == lastStone){
                    return true;
                }
                if(freq.find(pos) != freq.end()){
                    if(k - 1 > 0){
                        freq[pos].insert(k - 1);
                    }
                    freq[pos].insert(k);
                    freq[pos].insert(k + 1);
                }
            }
        }
        return false;
    }
};