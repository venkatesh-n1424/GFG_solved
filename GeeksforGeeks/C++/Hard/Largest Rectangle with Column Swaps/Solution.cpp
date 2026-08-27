class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<int> heights(m,0);
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    heights[j]++;
                }
                else heights[j]=0;
            }
            vector<int> sorted_heights=heights;
            sort(sorted_heights.begin(),sorted_heights.end(),greater<int>());
            int ht=INT_MAX,wt=0;
            for(int j=0;j<m;j++){
                ht=min(sorted_heights[j],ht);
                wt++;
                max_area=max(max_area,ht*wt);
            }
        }
        return max_area;
    }
};