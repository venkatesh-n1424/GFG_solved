class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int r = n - 1;
        deque<pair<long long, long long>> dq;
        long long op = 0;
        long long res = 0;

        for (int l = n - 1; l >= 0; --l) {
            long long nsize = 1;
            while (!dq.empty() && nums[l] >= dq.back().first) {
                auto [height, size] = dq.back();
                dq.pop_back();
                op += (nums[l] - height) * size;
                nsize += size;
            }
            dq.push_back({nums[l], nsize});

            while (op > k) {
                op -= dq.front().first - nums[r];
                dq.front().second -= 1;
                if (dq.front().second == 0) {
                    dq.pop_front();
                }
                r -= 1;
            }
            res += r - l + 1;
        }
        return res;
    }
};