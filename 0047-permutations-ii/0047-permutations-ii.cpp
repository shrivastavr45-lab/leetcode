class Solution {
public:
    vector<vector<int>>result;
    vector<int>perm;
    vector<bool>used;
    void backtrack(vector<int>& nums){
        
        if(perm.size()==nums.size()){
            result.push_back(perm);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])
                continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }
            used[i]=true;
            perm.push_back(nums[i]);
            backtrack(nums);
            perm.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        used.assign(nums.size(),false);
        backtrack(nums);
        return result;
    }
};