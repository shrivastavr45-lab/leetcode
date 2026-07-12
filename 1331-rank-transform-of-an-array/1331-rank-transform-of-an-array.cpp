class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>sorted=arr;
        sort(sorted.begin(),sorted.end());
        int r=1;
        unordered_map<int,int>mp;
        for(int x:sorted){
            if(mp.find(x)==mp.end()){
                mp[x]=r++;
            }
        }
        vector<int>result;
        for(int x:arr){
            result.push_back(mp[x]);
        }
        return result;
    }
};