class Solution {
public:
    int reverse(int x) {
        int min=pow(-2,31),max=pow(2,31)-1;
        int rev=0;
        while(x){
            int r=x%10;
            if(rev<min/10 ||(rev==min/10 && r<min%10))
            return 0;
            if(rev>max/10||(rev==max/10 && r>max%10))
            return 0;
            rev=rev*10+r;
            x/=10;

        }
        return rev;
    }
};