class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size() - 1, n2 = b.size() - 1;
        int carry = 0;
        string result = "";
        while(n1 >= 0 || n2 >= 0 || carry){
            int sum = carry;

            if(n1 >= 0) sum += a[n1--] - '0';
            if(n2 >= 0) sum += b[n2--] - '0';

            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};