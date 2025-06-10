class Solution {
public:
    int maximum69Number (int num) {
        int placevalue = 0;
        int placevaluesix = -1;
        int temp = num;
        while(num > 0)
        {
            int rem = num % 10;
            if(rem == 6)
            {
                placevaluesix = placevalue;
            }
            num = num/10;
            placevalue++;
        }
        if(placevaluesix == -1)
        {
            return temp;
        }
        return temp + 3 * pow(10,placevaluesix);
    }
};