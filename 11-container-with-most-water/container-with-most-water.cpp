class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int maxarea = 0;
        while(i < j)
        {
            int width = j - i;
            int h = min(height[i],height[j]);
            int area = width * h;
            maxarea = max(maxarea,area);
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return maxarea;
    }
};