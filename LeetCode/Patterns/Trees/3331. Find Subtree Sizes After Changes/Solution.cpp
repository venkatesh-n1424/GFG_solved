class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);

        auto dfs = [&](auto& self, int node) -> void {
            int curr = s[node] - 'a';
            int prev = last[curr];
            if (prev != -1) {
                parent[node] = prev;
            }
            last[curr] = node;
            for (int nei : adj[node]) {
                self(self, nei);
            }
            last[curr] = prev;
        };

        dfs(dfs, 0);

        vector<vector<int>> adj2(n);
        for (int i = 1; i < n; ++i) {
            adj2[parent[i]].push_back(i);
        }

        vector<int> memo(n, -1);

        auto dfs2 = [&](auto& self, int node) -> int {
            if (memo[node] != -1) {
                return memo[node];
            }
            int total = 1;
            for (int nei : adj2[node]) {
                total += self(self, nei);
            }
            return memo[node] = total;
        };

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = dfs2(dfs2, i);
        }

        return res;
    }
};