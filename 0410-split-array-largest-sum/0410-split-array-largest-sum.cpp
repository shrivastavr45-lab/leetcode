class Solution {
public:
    bool cansplit(vector<int>& nums,int k,int limit){
        int sum=0;
        int target=1;
        for(int num:nums){
            if(sum+num<=limit){
                sum+=num;
            }
            else{
                target++;
                sum=num;
            }
        }
        return target<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
        int mid=low+(high-low)/2;

            if(cansplit(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};