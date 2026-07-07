class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        long long x=0;
        int sum=0;
        for(char c:s){
            if(c!='0'){
                int t=c-'0';
                x=x*10+t;
                sum+=t;
            }
        }
        return x*sum;
    }
};