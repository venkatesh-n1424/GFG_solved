class Solution {
public:
    // bool ls(int x,vector<int>& nums){
    //     for(int i:nums){
    //         if(x==i) return true;
    //     }
    //     return false;
    // }
    int longestConsecutive(vector<int>& nums) {
        //brute
        if(nums.size()==0) return 0;
        int lc=1;
        // for(int i:nums){
        //     int c=1;
        //     int x=i;
        //     while(ls(x+1,nums)){
        //         c++;
        //         x++;
        //     }
        //     lc=max(c,lc);
        // }
        //better
        //sort(nums.begin(),nums.end());
        // int lastsmaller=INT_MIN,cntcur=0;
        // for(int i:nums){
        //     if(i-1==lastsmaller){
        //         cntcur++;
        //         lastsmaller=i;
        //     }
        //     else if(i!=lastsmaller){
        //         lastsmaller=i;
        //         cntcur=1;
        //     }
        //     lc=max(cntcur,lc);
        // }
        unordered_set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        for(int i:nums){
            if(s.find(i-1)==s.end()){
                int c=1;
                int x=i;
                while(s.find(x+1)!=s.end()){
                    c++;
                    x++;
                }
                lc=max(c,lc);
            }
        }
        return lc;
    }
};