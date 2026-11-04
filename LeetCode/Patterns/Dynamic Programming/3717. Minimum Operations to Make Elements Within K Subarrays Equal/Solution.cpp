class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        set<pair<long long, int>> l,h;
        long long ls = 0,hs=0;
        vector<long long> vals(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (h.empty() || nums[i] >= h.begin()->first) {
                h.insert({nums[i], i});
                hs += nums[i];
            } else {
                l.insert({nums[i], i});
                ls += nums[i];
            }
            
            if (i >= x) {
                long long val = nums[i - x];
                int idx = i - x;
                auto it_l = l.find({val, idx});
                if (it_l != l.end()) {
                    l.erase(it_l);
                    ls -= val;
                } else {
                    auto it_h = h.find({val, idx});
                    if (it_h != h.end()) {
                        h.erase(it_h);
                        hs -= val;
                    }
                }
            }
            
            while (h.size() > l.size() + 1) {
                auto it = h.begin(); 
                long long val = it->first;
                int idx = it->second;
                h.erase(it);
                hs -= val;
                l.insert({val, idx});
                ls += val;
            }
            
            while (h.size() < l.size()) {
                auto it = prev(l.end()); 
                long long val = it->first;
                int idx = it->second;
                l.erase(it);
                ls -= val;
                h.insert({val, idx});
                hs += val;
            }
            
            if (i >= x - 1) {
                long long median = h.begin()->first; 
                long long left_cost = (static_cast<long long>(l.size()) * median) - ls;
                long long right_cost = hs - (static_cast<long long>(h.size()) * median);
                vals[i] = left_cost + right_cost;
            }
        }
        
        long long INF = 1e16;
        vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));
        
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 0;
        }
        
        if (x - 1 < n) {
            dp[x - 1][1] = vals[x - 1];
        }
        
        for (int i = x; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], vals[i] + dp[i - x][j - 1]);
                }
            }
        }
        
        return dp[n - 1][k] >= INF ? -1 : dp[n - 1][k];
    }
};
