class Solution {
  public:
    vector<int> arr,state;
    int n;
    int solve(int i){
        if(i<0 || i>=n) return 1;
        if(state[i]==1 || state[i]==2) return state[i];
        if(arr[i]==0){
            state[i]=2;
            return 2;
        }
        if(state[i]==3) return 2;
        state[i]=3;
        int next=i+arr[i];
        int res=solve(next);
        state[i]=res;
        return res;
        
    }
    int goodIndices(vector<int> &arr) {
        // code here
        //brute TC-O(n^2) sc-O(n);
        // int n=arr.size();
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     vector<bool> visit(n,false);
        //     int j=i;
        //     while(!visit[j]){
        //         visit[j]=true;
        //         j+=arr[j];
        //         if(j>=n || j<0){
        //             cnt++;
        //             break;
        //         }
        //     }
        // }
        // return cnt;
        //TC-O(n) SC-O(n)
        /* 0->not visited
        1->good
        2->bad
        3->currently in dfs
        */
        this->arr=arr;
        n=arr.size();
        state=vector<int>(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(state[i]==0){
                solve(i);
            }
        }
        for(int i=0;i<n;i++){
            if(state[i]==1) cnt++;
        }
        return cnt;
    }
};