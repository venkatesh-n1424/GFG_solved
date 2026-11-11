class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(cost1+cost2<=costBoth){
            return (long long)need1*cost1+need2*cost2;
        }
        if(need1>need2){
            return (long long)costBoth*need2+(need1-need2)*min(cost1,costBoth);
        }
        return (long long)costBoth*need1+(need2-need1)*min(cost2,costBoth);
    }
};