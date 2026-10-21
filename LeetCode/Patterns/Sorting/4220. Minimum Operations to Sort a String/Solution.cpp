class Solution {
public:
    // bool sorted(string s){
    //     int n=s.size();
    //     bool sort=true;
    //     for(int i=1;i<n;i++){
    //         if(s[i]<s[i-1]){
    //             sort=false;
    //             break;
    //         }
    //     }
    //     return sort;
    // }
    int minOperations(string s) {
        //TC-O(nlogn)
        // int n=s.size();
        // if(sorted(s)) return 0;
        // if(n<3) return -1;
        // string t1=s,t2=s;
        // sort(t1.begin(),t1.begin()+n-1);
        // sort(t2.begin()+1,t2.end());
        // if(sorted(t1) || sorted(t2)) return 1;
        // t1=s;
        // t2=s;
        // sort(t1.begin(),t1.begin()+n-1);
        // sort(t1.begin()+1,t1.end());
        // sort(t2.begin()+1,t2.end());
        // sort(t2.begin(),t2.begin()+n-1);
        // if(sorted(t1) || sorted(t2)) return 2;
        // // t1=s;
        // // t2=s;
        // // sort(t1.begin(),t1.begin()+n-1);
        // // sort(t1.begin()+1,t1.end());
        // // sort(t1.begin(),t1.begin()+n-1);
        // // sort(t2.begin()+1,t2.end());
        // // sort(t2.begin(),t2.begin()+n-1);
        // // sort(t2.begin()+1,t2.end());
        // // if(sorted(t1) || sorted(t2)) return 3;
        // return 3;
        //TC-O(n) Sc-O(1)
        int n=s.size();
        bool sort=true;
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1]){
                sort=false;
                break;
            }
        }
        if(sort) return 0;
        if(n<3) return -1;
        char mn=s[0],mx=s[0];
        for(int i=1;i<n;i++){
            if(s[i]<=mn) mn=s[i];
            if(s[i]>=mx) mx=s[i];
        }
        if(s[0]==mn || s[n-1]==mx) return 1;
        for(int i=1;i<n-1;i++){
            if(s[i]==mn || s[i]==mx) return 2;
        }
        return 3;
    }
};