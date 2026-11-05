class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n1=arr1.size();
        int cnt=0;
        for(int& i:arr1){
            for(int& j:arr2){
                if(abs(i-j)<=d){
                    cnt++;
                    break;
                }
            }
        }
        return n1-cnt;
    }
};