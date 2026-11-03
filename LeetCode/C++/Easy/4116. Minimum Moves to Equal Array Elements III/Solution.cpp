class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele=*max_element(nums.begin(),nums.end());
        int cnt=0;
        for(int& i:nums) cnt+=abs(i-max_ele);
        return cnt;
    }
};