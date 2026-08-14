class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        if(x==0) return true;
        if(s>x) return false;
        int n=arr.size();
        vector<long> paper(n+1);
        paper[0]=s;
        long cursum=s;
        for(int i=0;i<n;i++){
            paper[i+1]=cursum+arr[i];
            cursum=cursum+paper[i+1];
        }
        //Greedy
        long target=x;
        for(int i=n;i>=0;i--){
            if(paper[i]<=target){
                target-=paper[i];
            }
        }
        return !(target);
        
    }
};