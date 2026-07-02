class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=nums[0];
        int currentmax=nums[0];
        for(int i=1;i<nums.size();i++){
            currentsum=max(nums[i],currentsum+nums[i]);
            currentmax=max(currentmax,currentsum);
        }
        return currentmax;
    }
};