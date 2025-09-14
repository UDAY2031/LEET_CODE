class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i : nums2){
            nums1.push_back(i);
        }
        nums1.erase(remove(nums1.begin(), nums1.end(), 0), nums1.end());
        sort(nums1.begin(), nums1.end());
    }
};