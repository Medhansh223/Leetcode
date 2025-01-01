class Solution {
public:
    int maxScore(string s) {
        int maxscore=0;
        int count0=0;
        int count1=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                count1++;
            }
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                count0++;
            }
            else
            {
                count1--;
            }
            maxscore=max(maxscore, count0+count1);
        }
        return maxscore;
    }
};