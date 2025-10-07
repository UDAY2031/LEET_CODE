class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> fullLakes(rains.size(), -1);
        stack<int> s;
        stack<int> s0;

        for(auto i : rains){
            if(i == 0){
                s0.push(i);
            }
        }
        for(int i = 0; i < rains.size(); i++){
            if(rains[i] > 0){
                s.push(rains[i]);
            }else if(s0.size() < s.size()){
                return {};
            }else if(rains[i] == 0){
                fullLakes[i] = s.top();
                s.pop();
            }
        }
        return fullLakes;
    }
};