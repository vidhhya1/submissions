class Solution {
public: 
    void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&grid){ 
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]) return; 
        vis[i][j]=true; 
        dfs(i+1,j,vis,grid);
        dfs(i,j+1,vis,grid); 
        dfs(i-1,j,vis,grid); 
        dfs(i,j-1,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        int cnt=0; 
        vector<vector<bool>>vis(n,vector<bool>(m,false)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(!vis[i][j] && grid[i][j]=='1'){ 
                    cnt++; 
                    dfs(i,j,vis,grid);
                }
            }
        } 
        return cnt;
    }
};
