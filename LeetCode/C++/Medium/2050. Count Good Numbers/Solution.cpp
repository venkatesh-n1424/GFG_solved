const int M=1e9+7;
class Solution {
public:
    long long int pow(int a,long long b){
        if(b==0) return 1;
        long long int ans=pow(a,b/2);
        ans=(ans*ans)%M;
        if(b%2==1) ans=(ans*a)%M;
        return ans;
    }
    
   
    int countGoodNumbers(long long n) {
        if(n%2==0){
            return (pow(5,n/2)*pow(4,n/2))%M;
        }
        else{
            return (pow(5,n/2+1)*pow(4,n/2))%M;
        }
    }
};