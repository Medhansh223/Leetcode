class Solution {
public:
    int prod(int n)
    {
        int ans = 1;
        while(n > 0)
        {
            ans = ans * (n % 10);
            n = n / 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;;i++)
        {
            if(prod(i) % t == 0)
            {
                return i;
            }
        }
        return -1;
    }
};