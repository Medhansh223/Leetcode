class Solution {
public:
    long long power(long long base, long long count, int mod) {
        long long result = 1;
        while (count > 0) {
            if(count % 2 == 1) 
            {
                result = (result * base) % mod;
                count = count - 1;
            }
            else
            {
                base = (base * base) % mod;
                count = count / 2;
            }
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        long long countevenplaces = (n+1)/2;
        long long countoddplaces = n/2;
        long long power5 = power(5, countevenplaces, mod);
        long long power4 = power(4, countoddplaces, mod);
        return (power5 * power4 % mod);
    }
};