class Solution {
public:
    const int MX=1e5+1;
    int sortableIntegers(vector<int>& nums) {
        vector<vector<int>> divisors(MX);
        
        divisors[1] = {1};
        for (int n = 2; n < MX; ++n) {
            divisors[n] = {1, n};
        }

        // Sieve-like loop to append proper divisors
        for (int i = 2; i < MX; ++i) {
            for (int j = i * 2; j < MX; j += i) {
                divisors[j].push_back(i);
            }
        }
        int n = nums.size();
        
        auto valid = [&](int d) -> bool {
            int prev_mx = 0;
            for (int i = d; i <= n; i += d) {
                int desc = -1;
                for (int j = i - d; j < i - 1; ++j) {
                    if (nums[j] > nums[j + 1]) {
                        if (desc != -1) {
                            return false;
                        }
                        desc = j + 1;
                    }
                }
                
                int mn, mx;
                if (desc != -1) {
                    if (nums[i - 1] > nums[i - d]) {
                        return false;
                    }
                    mn = nums[desc];
                    mx = nums[desc - 1];
                } else {
                    mn = nums[i - d];
                    mx = nums[i - 1];
                }
                
                if (mn < prev_mx) {
                    return false;
                }
                prev_mx = mx;
            }
            return true;
        };
        int res=0;
        for(auto& d:divisors[n]){
            if(valid (d)) res+=d;
        }
        return res;
    }
};