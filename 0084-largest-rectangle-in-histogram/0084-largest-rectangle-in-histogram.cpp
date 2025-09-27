class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl;
        vector<int> nsr;
        stack<int> s;
        
        nsl[0] = -1;
        for(int i = 1; i < n; i++){
            int curr = heights[i];
            while(!s.empty() && curr <= heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nsl[i] = -1;
            }else{
                nsl[i] = s.top();
            }
            s.push(curr);
        }

        while(!s.empty()){
            s.pop();
        }

        s.push(n-1);
        nsr[n-1] = n;
        for(int i = n - 2; i >= 0; i--){
            int curr = heights[i];
            while(!s.empty() && curr <= heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = s.top();
            }
            s.push(curr);
        }

        int area = 0;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            area = heights[i] * (nsr[i] - nsl[i] - 1);
            maxi = max(maxi, area);
        }
        return maxi;
    }
};