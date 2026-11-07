class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
        
        priority_queue<tuple<long long, int, int>, 
        vector<tuple<long long, int, int>>, 
                greater<tuple<long long, int, int>>> using_servers;
        
        for (int i = 0; i < servers.size(); ++i) {
            available.push({servers[i], i});
        }
        
        int n = tasks.size();
        vector<int> res;
        res.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            while (!using_servers.empty() && std::get<0>(using_servers.top()) <= i) {
                auto [et, w, s] = using_servers.top();
                using_servers.pop();
                available.push({w, s});
            }
            
            if (!available.empty()) {
                auto [w, s] = available.top();
                available.pop();
                using_servers.push({(long long)i + tasks[i], w, s});
                res.push_back(s);
            } else {
                auto [et, w, s] = using_servers.top();
                using_servers.pop();
                using_servers.push({et + tasks[i], w, s});
                res.push_back(s);
            }
        }
        
        return res;
    }
};