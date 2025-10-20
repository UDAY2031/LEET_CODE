class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;

        for(auto ch : operations){
            if(ch == "X++" || ch == "++X"){
                cnt++;
            }else{
                cnt--;
            }
        }
        return cnt;
    }
};