class Solution {
public: 
    vector<int>parent,size; 
    int find(int u){ 
        if(parent[u]==u) return u; 
        return parent[u]=find(parent[u]);
    } 
    bool uniondots(int u,int v){
        int ulp_u=find(u),ulp_v=find(v); 
        if(ulp_u==ulp_v) return false; 
        if(size[ulp_u]<=size[ulp_v]){ 
            parent[ulp_u]=ulp_v; 
            size[ulp_v]+=ulp_u;
        } 
        else{ 
             parent[ulp_v]=ulp_u; 
            size[ulp_u]+=ulp_v;
        } 
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(); 
        vector<vector<int>>adj; 
        for(int i=0;i<n;i++){ 
            for(int j=i+1;j<n;j++){ 
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]); 
                adj.push_back({d,i,j});
            }
        }  
        sort(adj.begin(),adj.end());
        int ans=0; 
        parent.resize(n);size.assign(n,1); 
        for(int i=0;i<n;i++) parent[i]=i; 
        for(auto it:adj){ 
           int dist=it[0],u=it[1],v=it[2]; 
           if(uniondots(u,v)) ans+=dist;
        }  
        return ans;
    }
};
