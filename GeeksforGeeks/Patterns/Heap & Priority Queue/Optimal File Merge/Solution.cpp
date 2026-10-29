class Solution {
  public:
    int minComputation(vector<int> &files) {
        // code here
        if(files.size()<2) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int& i:files) pq.push(i);
        int sum=0;
        while(!pq.empty()){
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            sum+=t1+t2;
            if(pq.empty()) break;
            pq.push(t1+t2);
        }
        return sum;
        
    }
};