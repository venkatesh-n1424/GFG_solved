class Solution {
public:
    int bs(int l, int h, vector<int>& arr,int t){
        if(l==h){
            if(arr[l]==t) return l;
            return -1;
        }
        int mid=(l+h)/2;
        if(arr[mid]>=t) return bs(l,mid,arr,t);
        else return bs(mid+1,h,arr,t);
    }
    int search(vector<int>& nums, int target) {
        return bs(0,nums.size()-1,nums,target);
    }
};