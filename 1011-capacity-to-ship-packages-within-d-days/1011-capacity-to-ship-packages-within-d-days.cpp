class Solution {
public:
    bool canload(vector<int>& weights,int cap,int days){
        int need=1;
        long long cur=0;
        for(int x:weights){
            if(cur+x>cap){
                need++;
                cur=0;
            }
            cur+=x;
        }
        return need<=days;
    } 
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()); 
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int mid=low+(high-low)/2;
            if(canload(weights,mid,days)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
