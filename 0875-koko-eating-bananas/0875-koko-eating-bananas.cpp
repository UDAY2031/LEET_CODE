class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){
            long long hrs = 0;
            int mid = low + (high - low) / 2;

            for(int pile : piles){
                hrs += ceil((double)pile/ mid);
            }

            if(hrs > h){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};