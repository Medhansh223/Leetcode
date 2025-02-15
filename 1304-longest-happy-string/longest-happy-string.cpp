class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a > 0)
        {
            pq.push({a,'a'});
        }
        if(b > 0)
        {
            pq.push({b,'b'});
        }
        if(c > 0)
        {
            pq.push({c,'c'});
        }
        string result = "";
        while(!pq.empty())
        {
            int freq1 = pq.top().first;
            char char1 = pq.top().second;
            pq.pop();
            if(result.length() >=2 && result[result.length() - 1] == char1 && result[result.length() - 2] == char1)
            {
                if(pq.empty())
                {
                    break;
                }
                else
                {
                    int freq2 = pq.top().first;
                    char char2 = pq.top().second;
                    pq.pop();
                    result.push_back(char2);
                    freq2--;
                    if(freq2 > 0)
                    {
                        pq.push({freq2, char2});
                    }
                }
            }
            else
            {
                result.push_back(char1);
                freq1--;
            }
            if(freq1>0)
            {
                pq.push({freq1, char1});
            }
        }
        return result;
    }
};