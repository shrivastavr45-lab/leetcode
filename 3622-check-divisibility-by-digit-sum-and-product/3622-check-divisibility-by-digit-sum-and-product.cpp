class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0, p=1;
        for(int i=n;i>0;i/=10){
            int r=i%10;
            s+=r;
            p*=r;
        }
        return n%(s+p)==0;
    }
};