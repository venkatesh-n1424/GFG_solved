class Solution {
public:
    typedef pair<int,int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> bcs(k,0);
        set<int> as;
        for(int i=0;i<k;i++) as.insert(i);
        priority_queue<P,vector<P>,greater<P>> bs;
        int n=arrival.size();
        for(int i=0;i<n;i++){
            while(!bs.empty() && bs.top().first<=arrival[i]){
                as.insert(bs.top().second);
                bs.pop();
            }
            auto it=as.lower_bound(i%k);
            if(it==as.end()){
                it=as.begin();
            }
            if(as.empty()) continue;
            int s=*it;
            bs.push({arrival[i]+load[i],s});
            as.erase(it);
            bcs[s]++;
        }
        vector<int> res;
        int max_req=*max_element(bcs.begin(),bcs.end());
        for(int i=0;i<k;i++){
            if(bcs[i]==max_req) res.push_back(i);
        }
        return res;

    }
};