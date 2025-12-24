class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int a = 0;
        for (int x : apple) {
            a += x;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        int b = 0, c = 0;
        for (int x : capacity) {
            b += x;
            c++;
            if (b >= a) {
                return c;
            }
        }

        return c;
    }
};