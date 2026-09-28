class Solution {
public: 
    int cnt;
    vector<bool>diag1,diag2,col; 
    void f(int r,int n,vector<string>&board){ 
        if(r==n) {cnt++;return;}
        for(int c=0;c<n;c++){  
            if(col[c]||diag1[r-c+n-1]||diag2[r+c]) continue; 
            board[r][c]='Q'; 
            col[c]=diag1[r-c+n-1]=diag2[r+c]=true; 
            f(r+1,n,board); 
            board[r][c]='.'; 
            col[c]=diag1[r-c+n-1]=diag2[r+c]=false; 
        }
    }
    int totalNQueens(int n) {
       vector<string>board(n,string(n,'.')); 
       col.resize(n,false); 
       diag1.resize(2*n-1,false); 
       diag2.resize(2*n-1,false); 
       f(0,n,board); 
       return cnt;
    }
};
