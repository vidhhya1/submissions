    class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int,int>>>adj(n+1); 
            for(auto it:times) adj[it[0]].push_back({it[1],it[2]}); 
            vector<int>dist(n+1,INT_MAX); 
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq; 
            pq.push({0,k}); 
            dist[k]=0; 
            while(!pq.empty()){ 
                int node=pq.top().second,t=pq.top().first; pq.pop();
                for(auto it:adj[node]){ 
                    if(dist[node]+it.second<dist[it.first]){ 
                        dist[it.first]=dist[node]+it.second; 
                        pq.push({dist[it.first],it.first});
                    }
                }
            } 
            int mini=INT_MIN; 
            for(int i=1;i<=n;i++){ 
                if(dist[i]==INT_MAX) return -1; 
                mini=max(mini,dist[i]);
            } 
            return mini;
        }
    };
