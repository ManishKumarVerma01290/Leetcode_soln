class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {1};
        }
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> freq;
        int val = temp[0];
        freq[val] = 1;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(val == temp[i]){
                freq[temp[i]] = count;
                continue;
            }
            count++;
            freq[temp[i]] = count;
            val = temp[i];
        }
        vector<int> temp2;
        for(int i = 0; i < n; i++){
            if(freq.find(arr[i]) != freq.end()){
                temp2.push_back(freq[arr[i]]);
            }
        }
        return temp2;       
    }
};