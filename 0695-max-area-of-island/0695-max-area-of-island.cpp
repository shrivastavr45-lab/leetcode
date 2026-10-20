class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        int row=grid.size();
        int col=grid[0].size();
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        return 1+
        dfs(grid,r+1,c)+dfs(grid,r-1,c)+dfs(grid,r,c+1)+dfs(grid,r,c-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    ans=max(ans,dfs(grid,r,c));
                }
            }
        }
        return ans;
    }
};