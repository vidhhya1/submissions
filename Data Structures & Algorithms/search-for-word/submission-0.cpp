class Solution {
public: 
    bool f(int i,int j,int k,vector<vector<char>>&board,string word){ 
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || k>word.length() ||word[k]!=board[i][j]) return false; 
        
        if(k==word.length()-1) return true; 
        char org=board[i][j]; 
        board[i][j]='#'; 
        bool found=f(i+1,j,k+1,board,word)||f(i-1,j,k+1,board,word)||f(i,j+1,k+1,board,word)||f(i,j-1,k+1,board,word); 
        board[i][j]=org; 
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size(); 
        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){ 
                if(board[i][j]==word[0]){  
                    
                    if(f(i,j,0,board,word)) return true; 
                }
            }
        } 
        return false;
    }
};
