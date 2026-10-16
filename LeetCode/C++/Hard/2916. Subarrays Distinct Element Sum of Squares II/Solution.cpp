class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int 
        int n=nums.size(),res=0;
        for(int i=0;i<n;i++){
            unordered_set<int> s;
            for(int j=i;j<n;j++){
                // TC-O(n^3)
                // unordered_set<int> s;
                // for(int k=i;k<=j;k++)
                //     if(!s.contains(nums[k])) s.insert(nums[k]);
                // res+=pow(s.size(),2);
                //TC-O(n^2)
                if(!s.contains(nums[j])) s.insert(nums[j]);
                res+=pow(s.size(),2);
            }
          
        }
        return res;
    }
};