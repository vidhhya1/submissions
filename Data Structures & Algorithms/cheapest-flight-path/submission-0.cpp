class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>>q; 
        q.push({0,0,src}); 
        vector<vector<pair<int,int>>>adj(n); 
        for(auto it:flights){ 
            adj[it[0]].push_back({it[1],it[2]});
        }  
        vector<int>dist(n,INT_MAX);dist[src]=0;
        while(!q.empty()){ 
             auto it=q.front();q.pop(); 
             int cost=it[0],stop=it[1],node=it[2]; 
             if(stop>k) continue; 
             for(auto adjnode:adj[node]){ 
                 if(dist[adjnode.first]>dist[node]+adjnode.second){ 
                    dist[adjnode.first]=dist[node]+adjnode.second; 
                    q.push({dist[adjnode.first],adjnode.first,stop+1});
                 }
             }
        } 
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
