class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int N=words.size();
        vector<int> pre(26,false);
        unordered_set<char> uqc;
        for(string& s:words){
            for(char& c:s) {
                uqc.insert(c);
                pre[c-'a']=true;
            }
        }
        int K=uqc.size();
        vector<vector<int>> adj(26);
          for(int i=0;i<N-1;i++){
              string s1=words[i],s2=words[i+1];
              int len=min(s1.size(),s2.size());
              int j=0;
              while(j<len && s1[j]==s2[j]) j++;
              if(j==len && s1.size()>s2.size()) return "";
              if(j<len){
                  int u=s1[j]-'a';
                  int v=s2[j]-'a';
                  if(find(adj[u].begin(),adj[u].end(),v)==adj[u].end()){
                      adj[u].push_back(v);
                  }
              }
          }
          vector<int> ind(26,0);
          for(int i=0;i<26;i++){
              for(auto& v:adj[i]){
                  ind[v]++;
              }
          }
          queue<int> q;
          for(int i=0;i<26;i++){
              if(pre[i] && !ind[i]) q.push(i);
          }
          string res="";
          while(!q.empty()){
              int t=q.front();
              q.pop();
              res+=(char)(t+'a');
              for(auto& v:adj[t]){
                  ind[v]--;
                  if(!ind[v]) q.push(v);
              }
          }
          if(res.size()!=K) return "";
          return res;
    }
};