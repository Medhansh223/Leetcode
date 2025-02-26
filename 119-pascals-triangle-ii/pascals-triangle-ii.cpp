class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
        {
            return {1};
        }
        if(rowIndex == 1)
        {
            return {1,1};
        }
        vector<int>prev;
        prev.push_back(1);
        prev.push_back(1);
        vector<int>curr;
        for(int i=2;i<=rowIndex;i++)
        {
            curr.push_back(1);
            for(int j=1;j<i;j++)
            {
                int num = prev[j] + prev[j-1];
                curr.push_back(num);
            }
            curr.push_back(1);
            prev = curr;
            curr.clear();
        }
        return prev;
    }
};