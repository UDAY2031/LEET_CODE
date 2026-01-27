class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int watertrap = 0;
        int left = 0;
        int right = n-1;
        int leftmax = height[0];
        int rightmax = height[n-1];

        while(left < right){
            if(height[left] < height[right]){
                if(leftmax < height[left]){
                    leftmax = height[left];
                }else{
                    watertrap += leftmax - height[left];
                }
                left++;
            }else{
                if(rightmax < height[right]){
                    rightmax = height[right];
                }else{
                    watertrap  += rightmax - height[right];
                }
                right--;

            }
        }
        return watertrap;
    }
};