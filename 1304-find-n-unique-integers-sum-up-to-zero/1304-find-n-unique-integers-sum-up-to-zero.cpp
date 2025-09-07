class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> temp;

        for(int i = 1; i <= n/2; i++){
            temp.push_back(i);
            temp.push_back(-i);
        }

        if(n % 2 != 0){
            temp.push_back(0);
        }
        return temp;
    }
};