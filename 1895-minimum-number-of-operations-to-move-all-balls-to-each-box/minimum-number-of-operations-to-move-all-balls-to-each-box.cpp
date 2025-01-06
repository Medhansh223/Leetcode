class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(boxes[j]=='1' && i!=j)
                {
                    sum=sum+abs(i-j);
                }
            }
            ans[i]=sum;
        }
        return ans;
    }
};