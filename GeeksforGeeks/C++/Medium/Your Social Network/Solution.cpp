class Solution {
  public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;

            int n = arr.size()+1;

                // process every user from 2->n

                for(int i=2;i<=n;i++){
                    vector<int> dist(n+1);

                    int current = i;
                    int jumps = 0;
                    int next = 0;

                    while(next != 1){
                        next = arr[current-2];
                        jumps++;
                        dist[next] = jumps;
                        current = next;
                    }

                    for(int j=1;j<i;j++){
                        if(dist[j] > 0){
                            ans.push_back({i,j,dist[j]});
                        }
                    }
                }
                return ans;
    }
};