class Solution {
public:
    int solve(vector<int>nums,int start,int end){
        int prev2=0;
        int prev1=0;
        for(int i=start;i<=end;i++){
            int pick=prev2+nums[i];
            int skip=prev1;
            int curr=max(pick,skip);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int pick1=solve(nums,0,n-2);
        int pick2=solve(nums,1,n-1);
        return max(pick1,pick2);
    }
};