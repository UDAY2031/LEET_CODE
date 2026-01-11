class Solution {
public:
    int f(vector<int>& h){
        stack<int> s;
        int n=h.size(),ans=0;
        for(int i=0;i<=n;i++){
            int x = (i==n ? 0 : h[i]);
            while(!s.empty() && x<h[s.top()]){
                int y = h[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                ans = max(ans, y * w);
            }
            s.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int n=matrix[0].size();
        vector<int> h(n,0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') h[j]++;
                else h[j]=0;
            }
            ans=max(ans,f(h));
        }
        return ans;
        
    }
};