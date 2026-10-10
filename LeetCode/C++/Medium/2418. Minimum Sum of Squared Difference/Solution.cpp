class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        long long k=(long long)k1+k2;
        priority_queue<int> pq;
        for(int i=0;i<n;i++) pq.push(abs(nums1[i]-nums2[i]));
        while(k>0 && pq.top()>0){
            int t=pq.top();
            pq.pop();
            pq.push(t-1);
            k--;
        }
        long long sum=0;
        while(!pq.empty()){
            long long t=pq.top();
            sum+=(t*t);
            pq.pop();
        }
        return sum;
    }
};