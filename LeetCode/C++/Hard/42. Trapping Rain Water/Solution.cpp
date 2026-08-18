class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        // vector<int> prefixmax(n),sufixmax(n);
        // prefixmax[0]=height[0];
        // for(int i=1;i<n;i++) prefixmax[i]=max(prefixmax[i-1],height[i]);
        // sufixmax[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--) sufixmax[i]=max(sufixmax[i+1],height[i]);
        int water=0;
        // for(int i=0;i<n;i++){
        //     int leftmax=prefixmax[i],rightmax=sufixmax[i];
        //     if(height[i]<leftmax && height[i]<rightmax)
        //     water+=(min(leftmax,rightmax)-height[i]);
        // }
        //Two-Pointer
        int lmax=0,rmax=0,l=0,r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]) water+=lmax-height[l];
                else lmax=height[l];
                l++;
            }
            else {
                if(rmax>height[r]) water+=rmax-height[r];
                else rmax=height[r];
                r--;
            }
        }
        return water;
    }
};