class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre(n,0);
        int operations=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            pre[i]=operations;
            if(boxes[i]=='1')
            {
                count++;
            }
            operations=operations+count;
        }
        vector<int>post(n,0);
        operations=0;
        count=0;
        for(int i=n-1;i>=0;i--)
        {
            post[i]=operations;
            if(boxes[i]=='1')
            {
                count++;
            }
            operations=operations+count;
        }
        for(int i=0;i<n;i++)
        {
            pre[i]=pre[i]+post[i];
        }
        return pre;
    }
};