class Solution {
public:
    bool check(int sq,int sum,int num)
    {
        if(sq==0)
        {
            return sum==num;
        }
        return check(sq/10,sum+sq%10,num) || check(sq/100,sum+sq%100,num) || check(sq/1000,sum+sq%1000,num) || check(sq/10000,sum+sq%10000,num); 
    }
    int punishmentNumber(int n) {
        int punish=0;
        for(int i=1;i<=n;i++)
        {
            int sq=i*i;
            if(check(sq,0,i))
            {
                punish=punish+sq;
            }
        }
        return punish;
    }
};