class Solution {
  public:
    // int getmin(vector<int>& arr,int i,int j){
    //     int n=arr.size();
    //     int min_ele=INT_MAX;
    //     for(int k=0;k<i;k++) min_ele=min(min_ele,arr[k]);
    //     for(int k=j+1;k<n;k++) min_ele=min(min_ele,arr[k]);
    //     return min_ele;
    // }
    // int getmax(vector<int>& arr,int i,int j){
    //     int n=arr.size();
    //     int max_ele=INT_MIN;
    //     for(int k=0;k<i;k++) max_ele=max(max_ele,arr[k]);
    //     for(int k=j+1;k<n;k++) max_ele=max(max_ele,arr[k]);
    //     return max_ele;
    // }
    int minDiff(int k, vector<int> &arr) {
        // code here
        int n=arr.size();
        int mindif=INT_MAX;
        //brute O(n^2)
        // for(int i=0;i<=n-k;i++){
        //     int min_ele=getmin(arr,i,i+k-1);
        //     int max_ele=getmax(arr,i,i+k-1);
        //     mindif=min(mindif,max_ele-min_ele);
        // }
        if(k==0){
            int max_ele=*max_element(arr.begin(),arr.end());
            int min_ele = *min_element(arr.begin(),arr.end());
            return max_ele-min_ele;
        }
        if(k==n-1) return 0;
        vector<int> premin(n),premax(n),sufmin(n),sufmax(n);
        premin[0]=arr[0];
        premax[0]=arr[0];
        for(int i=1;i<n;i++){
            premin[i]=min(premin[i-1],arr[i]);
            premax[i]=max(premax[i-1],arr[i]);
        }
        sufmin[n-1]=arr[n-1];
        sufmax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            sufmin[i]=min(sufmin[i+1],arr[i]);
            sufmax[i]=max(sufmax[i+1],arr[i]);
        }
        for(int i=0;i<=n-k;i++){
            int min_ele, max_ele;
            if(i>0 && i+k<n) {
                min_ele=min(premin[i-1],sufmin[i+k]);
                max_ele=max(premax[i-1],sufmax[i+k]);
            }
            else if(i+k<n){
                min_ele=sufmin[i+k];
                max_ele=sufmax[i+k];
            }
            else{
                max_ele=premax[i-1];
                min_ele=premin[i-1];
            }
            mindif=min(mindif,max_ele-min_ele);
        }
        return mindif;
    }
};
