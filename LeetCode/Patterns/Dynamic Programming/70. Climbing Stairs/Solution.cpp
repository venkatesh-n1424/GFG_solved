class Solution {
public:
    typedef struct{
        long long v11,v12,v21,v22;
    }mat;
    mat I(){
        return mat {1,0,0,1};
    }
    mat mul(mat a,mat b){
        return mat {
            a.v11*b.v11+a.v12*b.v21,
            a.v11*b.v12+a.v12*b.v22,
            a.v21*b.v11+a.v22*b.v21,
            a.v21*b.v12+a.v22*b.v22
        };
    }
    mat pow(mat a,int b){
        if(b==0) return I();
        mat ans=pow(a,b/2);
        ans=mul(ans,ans);
        if(b%2!=0) ans=mul(ans,a);
        return ans;
    }
    int climbStairs(int n) {
        mat fib=mat{1,1,1,0};
        if(n==1) return 1;
        if(n==2) return 2;
        mat pa=pow(fib,n-2);
        return 2*pa.v11+pa.v12;
    }
};