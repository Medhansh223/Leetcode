class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result=0;
        int bits=__builtin_popcount(num2);
        for(int i=31;i>=0 && bits>0;i--)
        {
            if((num1 >> i) & 1)
            {
                result=result | (1<<i);
                bits--;
            }
        }
        for(int i=0;i<32 && bits>0;i++)
        {
            if(!((num1 >> i) & 1))
            {
                result=result | (1<<i);
                bits--;
            }
        }
        return result;
    }
};