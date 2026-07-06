class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size()-2;
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=i;j<=m;j++){
                dp[i][j]=INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost=dp[i][k-1]+dp[k+1][j]+cuts[j+1]-cuts[i-1];
                    dp[i][j]=min(dp[i][j],cost);
                }
            }
        }
        return dp[1][m];
    }
};