class Solution {
public:
    int sum(int index){
        int sum=0;
        while(index>0){
            sum+=index%10;
            index/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==sum(nums[i])){
                return i;
            }
        }
        return -1;

    }
};