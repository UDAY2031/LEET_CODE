class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0, end = n - 1;
        int currsum = 0;

        while(start < end){
            currsum = numbers[start] + numbers[end];

            if(currsum == target){
                return {start+1, end+1};
            }else if(currsum > target){
                end--;
            }else{
                start++;
            }
        }
        return {};
    }
};