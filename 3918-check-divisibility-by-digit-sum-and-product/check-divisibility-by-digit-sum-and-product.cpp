class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int product = 1;
        while(n>0)
        {
            int rem = n % 10;
            sum = sum + rem;
            product = product * rem;
            n = n/10;
        }
        sum = sum + product;
        if(original % sum == 0)
        {
            return true;
        }
        return false;
    }
};