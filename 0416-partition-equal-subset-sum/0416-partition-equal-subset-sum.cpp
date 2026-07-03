class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        int result=sum/2;
        vector<int>dp(result+1,false);
        dp[0]=true;
        for(int num:nums){
            for(int i=result;i>=num;i--){
                dp[i]=dp[i]||dp[i-num];
            }
        }
        return dp[result];
    }
};