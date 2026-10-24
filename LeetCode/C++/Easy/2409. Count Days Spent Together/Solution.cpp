class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[13]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int pdays[13];
        pdays[0]=days[0];
        for(int i=1;i<13;i++){
            pdays[i]=pdays[i-1]+days[i];
        }
        int aa=pdays[stoi(arriveAlice.substr(0,2))-1]+stoi(arriveAlice.substr(3,2));
        int la=pdays[stoi(leaveAlice.substr(0,2))-1]+stoi(leaveAlice.substr(3,2));
        int ab=pdays[stoi(arriveBob.substr(0,2))-1]+stoi(arriveBob.substr(3,2));
        int lb=pdays[stoi(leaveBob.substr(0,2))-1]+stoi(leaveBob.substr(3,2));
        return min(la,lb)-max(aa,ab)+1;
    }
};