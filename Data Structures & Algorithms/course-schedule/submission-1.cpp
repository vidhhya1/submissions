class Solution {
public: 
    vector<bool>vis,pathvis;
    bool dfs(int node,vector<vector<int>>&adj){ 
        vis[node]=true; 
        pathvis[node]=true; 
        for(auto it:adj[node]){ 
            if(!vis[it]){ 
                if(dfs(it,adj)) return true;
            } 
            else if(pathvis[it]) return true;
        } 
        pathvis[node]=false; 
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        pathvis.assign(n,false);vis.assign(n,false); 
        vector<vector<int>>adj(n); 
        for(auto it:prerequisites){ 
            adj[it[1]].push_back(it[0]);
        } 
        for(int i=0;i<n;i++){ 
            if(!vis[i]){ 
                if(dfs(i,adj)) return false;
            }
        } 
        return true;
    }
};
