class Solution {
public:
    bool isAvailable(int seat, unordered_set<int>st)
    {
        if(st.find(seat) == st.end())
        {
            return true;
        }
        return false;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mpp;
        for(auto reservedSeat: reservedSeats)
        {
            int row = reservedSeat[0];
            int seat = reservedSeat[1];
            mpp[row].insert(seat);
        }
        int empty_rows = n - mpp.size();
        int result = empty_rows * 2;
        for(auto it : mpp)
        {
            int row = it.first;
            auto booked_seats = it.second;

            bool GroupA = isAvailable(2, booked_seats) & isAvailable(3, booked_seats) & isAvailable(4, booked_seats) & isAvailable(5, booked_seats);
            bool GroupB = isAvailable(4, booked_seats) & isAvailable(5, booked_seats) & isAvailable(6, booked_seats) & isAvailable(7, booked_seats);
            bool GroupC = isAvailable(6, booked_seats) & isAvailable(7, booked_seats) & isAvailable(8, booked_seats) & isAvailable(9, booked_seats);

            if(GroupA && GroupC)
            {
                result = result + 2;
            }
            else if(GroupA || GroupB || GroupC)
            {
                result = result + 1;
            }
        }
        return result;
    }
};