class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minidx=0,maxidx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<nums[minidx]){
                minidx=i;
            }
            if(nums[i]>nums[maxidx]){
                maxidx=i;
            }
        }
        if(minidx>maxidx){
            swap(minidx,maxidx);
        }
        int front=maxidx+1;
        int back=n-minidx;
        int both=(minidx+1)+(n-maxidx);

        return min({front,back,both});
    }
};