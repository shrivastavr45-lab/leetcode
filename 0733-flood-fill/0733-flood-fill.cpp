class Solution {
public:
    void dfs(vector<vector<int>>&image, int row,int col, int color,int oldcolor){
        int n=image.size();
        int m=image[0].size();
        if(row<0 || row>=n || col<0 || col>=m || image[row][col]!=oldcolor){
            return;
        }
        image[row][col]=color;
        dfs(image,row+1,col,color,oldcolor);
        dfs(image,row-1,col,color,oldcolor);
        dfs(image,row,col+1,color,oldcolor);
        dfs(image,row,col-1,color,oldcolor);        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        if(oldcolor==color){
            return image;
        }
        dfs(image,sr,sc,color,oldcolor);
        return image;
    }
};