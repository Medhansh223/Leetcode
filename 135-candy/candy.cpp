class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum++;
                i++;
                continue;
            }
            int up = 1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                up++;
                sum = sum + up;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                sum = sum + down;
                down++;
                i++;
            }
            if(down > up)
            {
                sum = sum + (down-up);
            }
        }
        return sum;
    }
};