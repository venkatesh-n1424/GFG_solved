class Solution {
public:
    int solve(int i,vector<int>& costs,int cost,int n){
        if(i==n) {
            return cost;
        }
        int i1=INT_MAX,i2=INT_MAX,i3=INT_MAX;
        if(i<n)
            i1=solve(i+1,costs,cost+costs[i]+1,n);
        if(i+1<n)
            i2=solve(i+2,costs,cost+costs[i+1]+4,n);
        if(i+2<n)
            i3=solve(i+3,costs,cost+costs[i+2]+9,n);
        return min(i1,min(i2,i3));
    }
    int climbStairs(int n, vector<int>& costs) {
        return solve(0,costs,0,n);
    }
};