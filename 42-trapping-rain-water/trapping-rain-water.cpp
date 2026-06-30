class Solution {
public:
    vector<int>generate_left_max(vector<int>& height)
    {
        int n = height.size();
        vector<int>leftmax(n);
        leftmax[0] = height[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i] = max(leftmax[i-1],height[i]);
        }
        return leftmax;
    }

    vector<int>generate_right_max(vector<int>& height)
    {
        int n = height.size();
        vector<int>rightmax(n);
        rightmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i] = max(rightmax[i+1],height[i]);
        }
        return rightmax;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftmax = generate_left_max(height);
        vector<int>rightmax = generate_right_max(height);
        int water = 0;
        for(int i=0;i<n;i++)
        {
            int w = 1;
            int h = min(leftmax[i],rightmax[i]) - height[i];
            if(h > 0)
            {
                water = water + w*h;
            }
        }
        return water;
    }
};