class Solution {
public:
    int gcd(int first,int last){
        if(last==0){
            return first;
        }
        return gcd(last,first%last);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first=nums[0], last=nums[nums.size()-1];
        int ans=gcd(first,last);
        return ans;
    }
};