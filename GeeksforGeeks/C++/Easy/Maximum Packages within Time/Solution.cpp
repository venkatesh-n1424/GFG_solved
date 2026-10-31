class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        if(totalTime>=arr.size()){
            int sum=0;
            for(int& i: arr) sum+=i;
            return sum;
        }
        int i=0,j=totalTime-1,n=arr.size();
        int maxp=0,sum=0;
        for(int k=0;k<=j;k++) sum+=arr[k];
        maxp=sum;
        j++;
        while(j<n){
            sum=sum+arr[j]-arr[i];
            maxp=max(maxp,sum);
            i++;
            j++;
        }
        return maxp;
    }
};