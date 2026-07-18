class Solution {
public:
    static bool cmp(pair<string,int>&a,pair<string,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string word:words){
            mp[word]++;
        }
        vector<pair<string,int>>v;
        for(auto x:mp)
            v.push_back(x);
        sort(v.begin(),v.end(),cmp);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};