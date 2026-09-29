class Solution {
public:int INF=INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(); 
        queue<pair<int,int>>q; 
        for(int i=0;i<m;i++){ 
            for(int j=0;j<n;j++){ 
                if(grid[i][j]==0) q.push({i,j});
            }
        }  
        vector<int>dx={1,-1,0,0},dy={0,0,1,-1};
        while(!q.empty()){ 
            int sz=q.size(); 
            for(int i=0;i<sz;i++){ 
            int r=q.front().first,c=q.front().second; 
            q.pop(); 
            for(int k=0;k<4;k++){ 
                int row=r+dx[k],col=c+dy[k]; 
                if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!=INF) continue; 
                grid[row][col]=grid[r][c]+1; 
                q.push({row,col});
            } 
            }
        } 

    }
};
