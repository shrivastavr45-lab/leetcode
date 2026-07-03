class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod=nums[0];
        int maxprod=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxprod,minprod);
            }
            minprod=min(nums[i],nums[i]*minprod);
            maxprod=max(nums[i],nums[i]*maxprod);
            result=max(result,maxprod);
        }
        return result;
    }
};