class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int x:nums){
            total+=x;
        }
        if(abs(target)<0){
            return 0;
        }
        if((total+target)%2){
            return 0;
        }
        int req=(total+target)/2;
        if(req<0){
            return 0;
        }
        vector<int>dp(req+1,0);
        dp[0]=1;
        for(int num:nums){
            for(int j=req;j>=num;j--){
                dp[j]+=dp[j-num];
            }
        }
        return dp[req];
    }
};