class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int left = 0;
        int right = n-1;
        int score = 0;
        int maxscore = 0;
        while(left <= right)
        {
            if(tokens[left] <= power)
            {
                power = power - tokens[left];
                score++;
                left++;
                maxscore = max(maxscore,score);
            }
            else if(score >= 1)
            {
                power = power + tokens[right];
                score--;
                right--;
            }
            else
            {
                break;
            }
        }
        return maxscore;
    }
};