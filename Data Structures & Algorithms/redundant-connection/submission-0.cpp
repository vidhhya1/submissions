class Solution {
public: 
    vector<int>parent; 
    vector<int>size;   
    int find(int u){ 
        if(parent[u]==u) return u; 
        return parent[u]=find(parent[u]);
    } 
    bool connected(int u,int v){ 
        return find(u)==find(v);
    }
    void unionnodes(int u,int v){ 
        int ulp_u=find(u),ulp_v=find(v); 
        if(ulp_u==ulp_v) return; 
        if(size[ulp_u]<=size[ulp_v]){ 
            parent[ulp_u]=ulp_v; 
            size[ulp_v]+=size[ulp_u];
        }  
        else{ 
            parent[ulp_v]=ulp_u; 
            size[ulp_u]+=size[ulp_v];
        }

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;  
        parent.resize(n);size.assign(n,1);
        for(int i=0;i<n;i++) parent[i]=i; 
        vector<int>ans(2); 
        for(auto it:edges){ 
            int u=it[0],v=it[1]; 
            if(connected(u,v)){ 
                ans[0]=u;ans[1]=v;
            } 
            else{ 
                unionnodes(u,v);
            }
        } 
        return ans;
    }
};
