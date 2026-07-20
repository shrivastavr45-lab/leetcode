class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> flat;

        for(auto &row:grid){
            for(int val:row){
                flat.push_back(val);
            }
        }
        int total=m*n;
        k=k%total;
        vector<int>rotated(total);
        for(int i=0;i<total;i++){
            rotated[(i+k)%total]=flat[i];
        }
        vector<vector<int>> result(m,vector<int>(n));
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j]=rotated[idx++];
            }

        }
        return result;
    }
};