class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int boats = 0;
        int l = 0;
        int r = n-1;
        while(l <= r)
        {
            if(people[l] + people[r] <= limit)
            {
                boats++;
                l++;
                r--;
            }
            else
            {
                boats++;
                r--;
            }
        }
        return boats;
    }
};