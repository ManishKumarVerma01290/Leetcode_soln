class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum_l = 0, sum_r = 0, left = 0, right = 0;
        for(int i = 0; i < n / 2; i++){
            if(num[i] == '?'){
                left++;
            }
            else{
                sum_l += num[i] - '0';
            }
        }
        for(int i = n / 2; i < n; i++){
            if(num[i] == '?'){
                right++;
            }
            else{
                sum_r += num[i] - '0';
            }
        }
        if((left + right) % 2 == 1){
            return true;
        }
        else{
            if(left > right) {
                if(sum_l - sum_r == -9 * (left - right) / 2){
                    return false;
                }
            }
            else if(right > left) {
                if(sum_l - sum_r == 9 * (right - left) / 2){
                    return false;
                }
            }
            else{
                if(sum_l == sum_r){
                    return false;
                }
            }
        }
        return true;
    }
};