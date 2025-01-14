class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int a=A.size();
        int b=B.size();
        map<int,int>mpp;
        vector<int>result;
        int i=0;
        while(i<a && i<b)
        {
            mpp[A[i]]++;
            mpp[B[i]]++;
            int count=0;
            for(auto it:mpp)
            {
                int freq=it.second;
                if(freq==2)
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