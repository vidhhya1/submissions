class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size(); 
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq; 
        pq.push({0,0,0}); 
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX)); 
        dist[0][0]=0;  
        vector<int>dx={1,-1,0,0},dy={0,0,1,-1};
        while(!pq.empty()){ 
            auto it=pq.top();pq.pop(); 
            int maxi=it[0],row=it[1],col=it[2]; 
            if(row==m-1 && col==n-1) return maxi; 
            for(int i=0;i<4;i++){ 
                int r=dx[i]+row,c=dy[i]+col; 
                if(r<0 || r>=m || c<0 || c>=n) continue;  
                int effort=max(maxi,abs(heights[row][col]-heights[r][c]));  
                if(dist[r][c]<=effort) continue;
                dist[r][c]=effort;pq.push({effort,r,c});
            }
        } 
        return -1;
    }
};