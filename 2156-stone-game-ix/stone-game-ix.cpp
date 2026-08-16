class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<stones.size();i++)
        {
            if(stones[i] % 3 == 0)
            {
                count0++;
            }
            else if(stones[i] % 3 == 1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
        }
        if(count0 % 2 == 0)
        {
            if(count1 >= 1 && count2 >= 1)
            {
                return true;
            }
            return false;
        }
        if((count2 - count1) > 2 || (count1 - count2) > 2)
        {
            return true;
        }
        return false;
    }
};