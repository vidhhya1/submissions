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
    void unionacc(int u,int v){ 
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) { 
        int n=accounts.size();  
        parent.resize(n);size.assign(n,1);
        for(int i=0;i<n;i++) parent[i]=i; 
        unordered_map<string,int>mpp; 
        
        for(int i=0;i<n;i++){ 
            for(int j=1;j<accounts[i].size();j++){ 
                string s=accounts[i][j]; 
                if(mpp.find(s)==mpp.end()) mpp[s]=i; 
                else unionacc(i,mpp[s]);
            }
        }  
        vector<vector<string>>group(n); 
        for(auto it:mpp){ 
            group[it.second].push_back(it.first);
        } 
        vector<vector<string>>ans; 
        for(int i=0;i<n;i++){ 
            if(group[i].size()>0){ 
                vector<string>curr;curr.push_back(accounts[i][0]); 
                sort(group[i].begin(),group[i].end()); 
                curr.insert(curr.end(),group[i].begin(),group[i].end()); 
                ans.push_back(curr);
            }
        }  
        sort(ans.begin(),ans.end());
        return ans;

    }
};