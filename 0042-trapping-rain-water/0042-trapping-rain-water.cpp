class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int leftmax = height[left], rightmax = height[right];
        int water_trapped = 0;
        while(left < right){
            if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax, height[left]);
                water_trapped += leftmax - height[left];
            }else{
                right--;
                rightmax = max(rightmax, height[right]);
                water_trapped += rightmax - height[right];
            }
        }
        return water_trapped;
    }
};