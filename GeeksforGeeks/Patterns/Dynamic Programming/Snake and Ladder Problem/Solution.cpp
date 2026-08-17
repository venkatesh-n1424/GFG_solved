class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        int total=n*n;
        vector<int> jump(total+1,0);
        for(int i=0;i<lad.size();i+=2){
            jump[lad[i]]=lad[i+1];
        }
        for(int i=0;i<sn.size();i+=2){
            jump[sn[i]]=sn[i+1];
        }
        vector<bool> visit(total+1);
        queue<vector<int>> q;
        q.push(vector<int>{1,0});
        visit[1]=true;
        while(!q.empty()){
            vector<int> cur=q.front();
            int cell=cur[0];
            int throwc=cur[1];
            if(cell==total) return throwc;
            for(int dice=1;dice<=6;dice++){
                int next=cell+dice;
                if(next>total) continue;
                if(jump[next]!=0){
                    next=jump[next];
                }
                if(!visit[next]){
                    visit[next]=true;
                    q.push(vector<int>{next,throwc+1});
                }
            }
            q.pop();
        }
        return -1;
    }
};