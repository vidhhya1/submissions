class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(n); 
       vector<int>indegree(n,0); 
       for(auto it:prerequisites){ 
        adj[it[1]].push_back(it[0]); 
        indegree[it[0]]++;
       }    
       queue<int>q;
       for(int i=0;i<n;i++){ 
        if(indegree[i]==0) q.push(i);
       }
       vector<bool>vis(n,false);  
       if(q.empty()) return false;
       while(!q.empty()){ 
          int node=q.front();q.pop(); 
          vis[node]=true;  
          for(auto it:adj[node]){ 
            if(!vis[it]){q.push(it);} 
            else if(it!=node) return false;
          }
       } 
       return true;
          
    }
};
