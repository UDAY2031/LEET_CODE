class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while(columnNumber > 0){
            int index = (columnNumber - 1) % 26;
            result.push_back(index + 'A');
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};