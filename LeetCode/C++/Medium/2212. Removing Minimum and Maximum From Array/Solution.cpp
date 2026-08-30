class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minele=INT_MAX,maxele=INT_MIN,maxidx,minidx;
        int mind;
        for(int i=0;i<n;i++){
            if(nums[i]>maxele){
                maxele=nums[i];
                maxidx=i;
            }
            if(nums[i]<minele){
                minele=nums[i];
                minidx=i;
            }
        }
        int mid=n/2;
        if(minidx<=mid && maxidx<=mid){
           if(maxidx>minidx) mind = maxidx+1;
           else mind=minidx+1; 
        }
        else if(minidx>=mid && maxidx>=mid){
            if(maxidx<minidx) mind = n-maxidx;
           else mind= n-minidx; 
        }
        else{
            if(maxidx<minidx){
                mind= (maxidx+1) + (n-minidx);
            }
           else mind= (minidx+1) + (n-maxidx);
        }
        return mind;
    }
};