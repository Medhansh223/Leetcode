class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int a=A.size();
        int b=B.size();
        map<int,int>mpp;
        vector<int>result;
        int i=0;
        int count=0;
        while(i<a && i<b)
        {
            mpp[A[i]]++;
            mpp[B[i]]++;
            if(A[i]==B[i])
            {
                count++;
            }
            else
            {
                if(mpp[A[i]]==2)
                {
                    count++;
                }
                if(mpp[B[i]]==2)
                {
                    count++;
                }
            }
            result.push_back(count);
            i++;
        }
        return result;
    }
};