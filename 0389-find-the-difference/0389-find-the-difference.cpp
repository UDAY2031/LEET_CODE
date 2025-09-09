class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> temp(26,0);
        
        for(auto it : t){
            temp[it - 'a']++;
        }
        for(auto it : s){
            temp[it - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(temp[i] > 0){
                return i + 'a';
            }
        }
        return {};
    }
};