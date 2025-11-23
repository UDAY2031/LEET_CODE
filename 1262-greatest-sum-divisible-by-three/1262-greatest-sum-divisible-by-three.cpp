class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> v1;
        vector<int> v2;

        for(auto x : nums){
            sum += x;
            if(x % 3 == 1){
                v1.push_back(x);
            }else if(x % 3 == 2){
                v2.push_back(x);
            }
        }
        if(sum % 3 == 0){
            return sum;
        }
        int ans = 0;
        
        if(sum % 3 == 1){

            int r1 = v1.size() > 0 ? v1[0] : INT_MAX;

            int r2 = v2.size() > 1 ? v2[0] + v2[1] : INT_MAX;

            ans = sum - min(r1, r2);

        }else{
            int r1 = v2.size() > 0 ? v2[0] : INT_MAX;

            int r2 = v1.size() > 1 ? v1[0] + v1[1] : INT_MAX;

            ans = sum - min(r1,r2);
        }
        return ans;
    }
};