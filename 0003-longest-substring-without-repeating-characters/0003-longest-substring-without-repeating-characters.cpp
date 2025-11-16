class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0, left = 0, maxlen = 0;
        
        unordered_set<char> st;

        while(right < s.size()){
            if(st.find(s[right]) == st.end()){
                st.insert(s[right]);

                maxlen = max(maxlen, right - left + 1);
                right++;
            }else{
                st.erase(s[left++]);
            }
        }
        return maxlen;
    }
};