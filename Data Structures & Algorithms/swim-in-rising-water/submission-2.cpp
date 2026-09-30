class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(); 
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX)); 
        dist[0][0]=grid[0][0]; 
        priority_queue<vector<int>,vector<vector<int>>,greater<>>q;
        q.push({grid[0][0],0,0}); 
        vector<int>dx={1,-1,0,0},dy={0,0,1,-1}; 
        while(!q.empty()){ 
            auto it=q.top();q.pop(); 
            int maxi=it[0],row=it[1],col=it[2];  
            if(row==n-1 && col==n-1) return maxi;
            if(dist[row][col]<maxi) continue; 
            for(int k=0;k<4;k++){ 
                int r=dx[k]+row,c=dy[k]+col; 
                if(r<0 || r>=n || c<0 || c>=n) continue; 
                int level=max(maxi,grid[r][c]); 
                if(dist[r][c]>level){ 
                    dist[r][c]=level; 
                    q.push({dist[r][c],r,c});
                }
            }
        } 
        return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1];
    }
};
