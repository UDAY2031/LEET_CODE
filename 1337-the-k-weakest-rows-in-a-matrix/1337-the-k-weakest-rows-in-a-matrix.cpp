class ROW{
public:
    int idx;
    int cnt;

    ROW(int cnt, int idx){
        this->idx = idx;
        this->cnt = cnt;
    }

    bool operator < (const ROW &obj) const{
        if(this->cnt == obj.cnt){
            return this->idx > obj.idx;
        }
        return this->cnt > obj.cnt;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<ROW> rows;

        for(int i = 0; i < mat.size(); i++){
            int cnt = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1){
                    cnt++;
                }
            }
            rows.push_back(ROW(cnt,i));
        }
        priority_queue<ROW> pq(rows.begin(), rows.end());
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top().idx);
            pq.pop();
        }
        return res;
    }
};