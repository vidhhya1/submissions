class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>order; 
        vector<vector<int>>adj(n);  
        vector<int>indegree(n,0); 
        for(auto it:prerequisites){ 
            adj[it[1]].push_back(it[0]);indegree[it[0]]++;
        } 
        queue<int>q;
        for(int i=0;i<n;i++){ 
            if(indegree[i]==0) q.push(i);
        } 
        while(!q.empty()){ 
            int node=q.front();q.pop(); 
            order.push_back(node); 
            for(auto it:adj[node]){ 
                if(--indegree[it]==0) q.push(it);
            }
        } 
        if(order.size()<n) return {};
        return order;
    }
};
