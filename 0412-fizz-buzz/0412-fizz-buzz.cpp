class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n); // Pre-allocate memory for size n
        
        for(int i = 1; i <= n; i++) {
            bool divisibleBy3 = (i % 3 == 0);
            bool divisibleBy5 = (i % 5 == 0);
            
            if(divisibleBy3 && divisibleBy5) {
                result[i - 1] = "FizzBuzz";
            }
            else if(divisibleBy3) {
                result[i - 1] = "Fizz";
            }
            else if(divisibleBy5) {
                result[i - 1] = "Buzz";
            }
            else {
                result[i - 1] = to_string(i);
            }
        }
        
        return result;
    }
};
