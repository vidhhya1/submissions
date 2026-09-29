class Solution {
public:  
int cnt;
void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid){ 
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || vis[i][j]) return; 
        vis[i][j]=true; cnt++;
        dfs(i+1,j,vis,grid);
        dfs(i,j+1,vis,grid); 
        dfs(i-1,j,vis,grid); 
        dfs(i,j-1,vis,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        int maxi=0; 
        vector<vector<bool>>vis(n,vector<bool>(m,false)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(!vis[i][j] && grid[i][j]==1){ 
                    cnt=0;
                    dfs(i,j,vis,grid); 
                    maxi=max(maxi,cnt);
                }
            }
        } 
        return maxi;
    }
};
