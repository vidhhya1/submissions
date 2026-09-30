class Solution {
public:
    vector<string>ans;  
    unordered_set<int>done;
    void dfs(string node,unordered_map<string,vector<pair<string,int>>>&mpp){ 
        ans.push_back(node);  
        for(auto it:mpp[node]){  
            if(done.count(it.second)) continue; 
            done.insert(it.second);
            dfs(it.first,mpp);
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<pair<string,int>>>mpp; 
        int i=0; 
        for(auto it:tickets){ 
            mpp[it[0]].push_back({it[1],i++});
        } 
        for(auto& it:mpp){ 
            sort(it.second.begin(),it.second.end());
        }  
        dfs("JFK",mpp); 
        return ans;
    }
};
