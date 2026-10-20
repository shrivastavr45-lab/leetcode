class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int k=1;k<=n;k++){
            if(n%k != 0) continue;
            bool valid=true;
            for(int start=0;start<n && valid; start+=k){
                bool found=false;
                for(int shift=0;shift<k && !found ;shift++){
                    bool match=true;
                    for(int j=0;j<k;j++){
                        if(nums[start + (j+shift)%k]!= sorted[start+j]){
                            match=false;
                            break;
                        }
                    }
                    if(match) found=true;
                }
                if(!found) valid=false;
            }
            if(valid)ans+=k;

        }
        return ans;
    }
};