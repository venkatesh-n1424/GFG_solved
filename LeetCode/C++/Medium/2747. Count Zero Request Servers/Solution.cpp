class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q=queries.size();
        unordered_map<int,int> mpp;
        sort(logs.begin(),logs.end(),[](auto a,auto b){
            return a[1]<b[1];
        });
        vector<vector<int>> que;
        for(int i=0;i<q;i++){
            que.push_back({i,queries[i]});
        }
        sort(que.begin(),que.end(),[](auto a,auto b){
            return a[1]<b[1];
        });
        int l=0,r=0;
        vector<int> res(q);
        for(auto& iq:que){
            while(r<logs.size() && logs[r][1]<=iq[1]){
                int s=logs[r][0];
                mpp[s]++;
                r++;
            }
            while(l<r && logs[l][1]<iq[1]-x){
                int s=logs[l][0];
                mpp[s]--;
                if(mpp[s]==0) mpp.erase(s);
                l++;
            }
            res[iq[0]]=n-mpp.size();
        }
        return res;
    }
};