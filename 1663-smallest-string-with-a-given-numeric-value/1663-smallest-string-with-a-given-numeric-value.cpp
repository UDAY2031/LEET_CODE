class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        while(n != 0){
            int ch = k - (n - 1) * 26;
            if(ch <= 0){
                ans.push_back('a');
                n--;
                k--;
            }else{
                ans.push_back(ch + 'a'-1);
                n--;
                k -= (ch);
            }
        }
        return ans;
    }
};