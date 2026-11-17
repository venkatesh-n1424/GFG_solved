class Solution {
  public:
    bool findPattern(string& s) {
        // code here
       int i=0;
       while(i<s.length()){
           int x=0;
           int y=0;
           while(i<s.length() and s[i]=='x'){
               x++;
               i++;
           }
           while(i<s.length() and s[i]=='y'){
               y++;
               i++;
           }
           if(x!=y) return false;  
       }
       return true; 
    }
};