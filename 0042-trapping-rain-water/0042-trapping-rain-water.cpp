class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax[20000],rightmax[20000];
        leftmax[0] = height[0];
        int n = height.size();
        rightmax[n-1] = height[n-1];

        for(int i = 1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],height[i-1]);
        }
        for(int i = n-2;i >= 0;i--){
            rightmax[i] = max(rightmax[i+1],height[i+1]);
        }
        int watertrapped = 0;
        for(int i = 0;i < n;i++){
            int curr = min(leftmax[i],rightmax[i]) - height[i];
            if(curr > 0){
                watertrapped += curr;
            }
        }
        return watertrapped;
    }
};