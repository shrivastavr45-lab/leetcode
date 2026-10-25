class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int suffix=1;
        int prefix=1;
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=suffix;
            suffix*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=prefix;
            prefix*=nums[i];
        }
        return ans;
    }
};