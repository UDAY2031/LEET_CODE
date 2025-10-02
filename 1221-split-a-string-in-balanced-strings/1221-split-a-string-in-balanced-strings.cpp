class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int countR = 0;
        int countL = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R'){
                countR++;
            }else{
                countL++;
            }
            if(countR == countL){
                ans++;
                countR = 0;
                countL = 0;
            }
        }
        return ans;
    }
};