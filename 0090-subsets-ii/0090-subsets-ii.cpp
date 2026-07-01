class Solution {
public:
    vector<int>subset;
    vector<vector<int>>result;
    void backtrack(int index,vector<int>&nums){
        result.push_back(subset);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            subset.push_back(nums[i]);
            backtrack(i+1,nums);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,nums);
        return result;
    }
};