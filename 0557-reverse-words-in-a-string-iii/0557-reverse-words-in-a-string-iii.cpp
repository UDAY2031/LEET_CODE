class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }
        string res;
        for(int i = 0; i < words.size(); i++){
            reverse(words[i].begin(), words[i].end());
            res += words[i];

            if(i < words.size() - 1) res += " ";
        }
        return res;
    }
};