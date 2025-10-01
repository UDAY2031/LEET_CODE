class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string ch : tokens){
            if(isdigit(ch[0]) || (ch.size() > 1 && ch[0] == '-')){
                s.push(stoi(ch));
            }else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(ch == "+"){
                    s.push(a + b);
                }else if(ch == "-"){
                    s.push(b - a);
                }else if(ch == "*"){
                    s.push(a * b);
                }else if(ch == "/"){
                    s.push(b / a);
                }
            }
        }
        return s.top();
    }
};