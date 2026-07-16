class Solution {
public:
    long long gcd(long long a,long long b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixGrid(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGrid[i]=gcd(nums[i],mx);
        }
        sort(prefixGrid.begin(),prefixGrid.end());
        long long ans=0;
        int l=0,r=n-1;
        while(l<r){
            ans+=gcd(prefixGrid[l],prefixGrid[r]);
            l++;
            r--;
        }
        return ans;
    }
};