class Solution {
public:
    string decodeString(string s) {
        stack<int> cnt;
        stack<string> s1;
        int n = 0;
        string sub;

        for(char c : s){
            if(isdigit(c)){
                n = n * 10 + (c - '0');
            }else if(c == '['){
                cnt.push(n);
                n = 0;
                s1.push(sub);
                sub = "";
            }else if(c == ']'){
                int k = cnt.top();
                cnt.pop();
                string temp = sub;
                sub = s1.top();
                s1.pop();
                while(k-- > 0){
                    sub += temp;
                }
            }else{
                sub += c;
            }
        }
        return sub;
    }
};