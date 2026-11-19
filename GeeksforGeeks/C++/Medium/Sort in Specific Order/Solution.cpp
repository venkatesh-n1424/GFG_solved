class Solution {
  public:
    bool odd(int n){
            return n&1;
        }
        void mergesort(vector<int>& arr,int low,int high){
            if(low>=high) return;
            int mid = (low+high)/2;
            mergesort(arr,low,mid);
            mergesort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
        void merge(vector<int>& arr,int low,int mid,int high){
            vector<int> temp;
            int left=low,right=mid+1;
            while(left<=mid && right<=high){
                if(odd(arr[left]) && odd(arr[right])){
                    if(arr[left]>=arr[right]) temp.emplace_back(arr[left++]);
                    else temp.emplace_back(arr[right++]);
                }
                else if(!odd(arr[left]) && !odd(arr[right])){
                    if(arr[left]<=arr[right]) temp.emplace_back(arr[left++]);
                    else temp.emplace_back(arr[right++]);
                }
                else{
                    if(odd(arr[left])) temp.emplace_back(arr[left++]);
                    else temp.emplace_back(arr[right++]);
                }
            }
            while(left<=mid){
                temp.emplace_back(arr[left++]);
            }
            while(right<=high){
                temp.emplace_back(arr[right++]);
            }
            for(int i=low;i<=high;i++){
                arr[i]=temp[i-low];
            }
        }
        void sortIt(vector<int>& arr) {
            // code here
            mergesort(arr,0,arr.size()-1);
        }
};