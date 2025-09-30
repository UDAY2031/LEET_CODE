class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentgas = 0;
        int totalgas = 0;
        int startidx = 0;

        for(int i = 0; i < gas.size(); i++){

            currentgas += gas[i] - cost[i];

            totalgas += gas[i] - cost[i];

            if(currentgas < 0){
                startidx = i+1;
                currentgas = 0;
            }
        }
        return totalgas >= 0 ? startidx : -1;
    }
};