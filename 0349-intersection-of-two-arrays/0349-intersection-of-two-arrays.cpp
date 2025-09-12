class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n1(1001,0);
        vector<int> n2(1001,0);
        vector<int> result;

        for(int i = 0; i < nums1.size(); i++){
            n1[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++){
            n2[nums2[i]] = 1;
        }
        for(int i = 0; i <= 1000; i++){
            if(n1[i] == 1 && n2[i] == 1){
                result.push_back(i);
            }
        }
        return result;
    }
};