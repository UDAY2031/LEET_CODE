class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, char> ms, mt;

        for(int i = 0; i < s.size(); i++){
            char c1 = s[i], c2 = t[i];

            if(ms.count(c1) && ms[c1] != c2) return false;
            if(mt.count(c2) && mt[c2] != c1) return false;

            ms[c1] = c2;
            mt[c2] = c1;
        }
        return true;
    }
};