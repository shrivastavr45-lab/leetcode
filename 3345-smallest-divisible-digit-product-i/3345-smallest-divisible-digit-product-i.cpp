class Solution {
public:
    long long prod(long long x){
        long long product=1;
        while(x>0){
            product*=(x%10);
            x/=10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(prod(n)%t==0){
                return n;
            }
            n++;
        }
    }
};