class Solution {
public:
    int rows=0, cols=0;
    bool bfs(vector<vector<char>>& board,string word,int r,int c,int index){
        if(index==word.size()){
            return true;
        }
        if(c>=cols || r>=rows || c<0 || r<0|| board[r][c]!=word[index]){
            return false;
        }
        int temp=board[r][c];
        board[r][c]='#';
        bool found=
            bfs(board,word,r+1,c,index+1)||
            bfs(board,word,r-1,c,index+1)||
            bfs(board,word,r,c+1,index+1)||
            bfs(board,word,r,c-1,index+1);
        board[r][c]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(bfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};