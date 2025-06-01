class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        int miniF = max(0 , n - 2*limit );
        int maxiF = min(limit, n);

        for(int i = miniF ; i <= maxiF ; i++){
            int rem = n - i;
            int miniS = max(0 , rem - limit);
            int maxiS = min(rem,limit);

            cnt += maxiS - miniS + 1;
        }
        return cnt;
    }
    
};