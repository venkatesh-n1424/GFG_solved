class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        //brute->O(n^2)
        // bool res=false;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums.at(i)==nums.at(j)){
        //             res = true;
        //             break;
        //         }
        //     }
        // }
        // return res;
        //optimal->O(n)
        // map<int ,int> val;
        // for(int i=0;i<n;i++){
        //     val[nums.at(i)]++;
        // }
        // if(val.size()<n) return true;
        // return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums.at(i)==nums.at(i+1)) return true;
        }
        return false;
    }
};