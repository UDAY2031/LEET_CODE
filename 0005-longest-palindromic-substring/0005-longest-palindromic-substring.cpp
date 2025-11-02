class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxi = 1;

        auto expand = [&](int left, int right){
            while(left >= 0 && right < n && s[left] == s[right]){
                int curr = right - left + 1;
                if(curr > maxi){
                    start = left;
                    maxi = curr;
                }
                left--;
                right++;
            }
        };

        for(int i = 0; i < n; i++){
            expand(i, i);

            expand(i, i + 1);
        }
        return s.substr(start, maxi);
    }
};