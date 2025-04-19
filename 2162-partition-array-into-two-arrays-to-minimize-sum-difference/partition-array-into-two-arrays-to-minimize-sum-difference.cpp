class Solution {
public:
    void generateSums(vector<int>& nums, int start, int end, unordered_map<int, vector<int>>& sumMap) {
        int len = end - start;
        for (int mask = 0; mask < (1 << len); mask++) {
            int sum = 0, count = 0;
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) {
                    sum += nums[start + i];
                    count++;
                }
            }
            sumMap[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        unordered_map<int, vector<int>> leftSums, rightSums;
        generateSums(nums, 0, n, leftSums);
        generateSums(nums, n, 2 * n, rightSums);

        // Sort all vectors in rightSums to enable binary search
        for (auto& [_, vec] : rightSums) {
            sort(vec.begin(), vec.end());
        }

        int minDiff = INT_MAX;

        for (int i = 0; i <= n; i++) {
            auto& left = leftSums[i];
            auto& right = rightSums[n - i];

            for (int sumLeft : left) {
                int target = totalSum / 2 - sumLeft;
                auto& vec = right;

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int sum = sumLeft + *it;
                    minDiff = min(minDiff, abs(totalSum - 2 * sum));
                }
                if (it != vec.begin()) {
                    --it;
                    int sum = sumLeft + *it;
                    minDiff = min(minDiff, abs(totalSum - 2 * sum));
                }
            }
        }

        return minDiff;
    }
};
