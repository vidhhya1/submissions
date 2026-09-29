class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(); 
        queue<pair<int,int>>q; 
        int total=0; 
        for(int i=0;i<m;i++){ 
            for(int j=0;j<n;j++){ 
                if(grid[i][j]==2) q.push({i,j}); 
                if(grid[i][j]!=0) total++;
            }
        }   
        int minutes=0;
        vector<int>dx={1,-1,0,0},dy={0,0,1,-1};
        while(!q.empty()){ 
             int sz=q.size();   
             total-=sz;
             for(int i=0;i<sz;i++){ 
                int row=q.front().first,col=q.front().second; 
                q.pop(); 
                for(int k=0;k<4;k++){ 
                    int r=row+dx[k],c=col+dy[k]; 
                    if(r<0 || r>=m || c<0 ||c>=n||grid[r][c]!=1) continue; 
                    q.push({r,c});grid[r][c]=2;
                }
             } 
             if(!q.empty())minutes++;
        } 
        return total==0?minutes:-1;
    }
};
