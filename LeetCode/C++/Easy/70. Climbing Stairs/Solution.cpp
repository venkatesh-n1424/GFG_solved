class Solution {
public:
    typedef struct{
        int m[2][2];
    }mat;
    mat iden(){
        mat I={
        {{1,0},{0,1}}
        };
        return I;
    }
    mat mul(mat &a,mat &b){
        mat c={
            {{0,0},{0,0}}
        };
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    c.m[i][j]+=a.m[i][k]*b.m[k][j];
                }
            }
        }
        return c;
    }
    mat pow(mat &a,int b){
        if(b==0) return iden();
        mat ans=pow(a,b/2);
        ans=mul(ans,ans);
        if(b%2!=0) ans=mul(ans,a);
        return ans;
    }
    int climbStairs(int n) {
        if(n==1) return 1;
        mat a={{{1,1},{1,0}}};
        mat p=pow(a,n-1);
        return p.m[0][0]+p.m[0][1];
    }
};