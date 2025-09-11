class Solution {
public:

    bool isvowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    string sortVowels(string s) {
        int n = s.size();
        vector<int> vowels;

        for(auto ch : s){
            if(isvowel(ch)){
                vowels.push_back(ch);
            }
        }

        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for(int i = 0; i <= n; i++){
            if(isvowel(s[i])){
                s[i] = vowels[idx++];
            }
        }
        return s;
    }
};