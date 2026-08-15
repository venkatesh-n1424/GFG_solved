class Solution {
  public:
    int countWithout(int n, int d) {
        // code here
        if(n==0) return 0;
        string str = to_string(n);
        int digits=str.size();
        int c=0;
        for(int i=1;i<digits;i++){
            if(i==1){
                c+=((d==0)?9:8);
            }
            else{
                int firstchoices=(d==0)?9:8;
                c+=(firstchoices*pow(9,i-1));
            }
        }
        for(int i=0;i<digits;i++){
            int curd=str[i]-'0';
            int start=(i==0)?1:0;
            for(int digit=start;digit<curd;digit++){
                if(digit==d) continue;
                c+=pow(9,digits-i-1);
            }
            if(curd==d) return c;
        }
        return c+1;
        
    }
};