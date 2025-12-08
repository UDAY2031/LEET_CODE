class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(i * i + j * j <= n){
                    cnt++;
                }
            }
        }
        return cnt-1;
    }
};