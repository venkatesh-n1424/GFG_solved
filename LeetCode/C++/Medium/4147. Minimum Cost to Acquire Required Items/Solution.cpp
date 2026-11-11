class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<=costBoth){
            return (ll)need1*cost1+(ll)need2*cost2;
        }
        if(need1>need2){
            return (ll)costBoth*need2+(ll)(need1-need2)*min(cost1,costBoth);
        }
        return (ll)costBoth*need1+(ll)(need2-need1)*min(cost2,costBoth);
    }
};