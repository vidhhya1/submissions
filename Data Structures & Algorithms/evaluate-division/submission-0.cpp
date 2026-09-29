class Solution {
public: 
   double dfs(string src,string dst, unordered_map<string,unordered_map<string,double>>&mpp,unordered_set<string>&vis){ 
    if(src==dst) return 1.0; 
    vis.insert(src); 
    for(auto adjnode:mpp[src]){ 
        string s1=adjnode.first; 
        double val=adjnode.second; 
        if(vis.count(s1)==0){ 
            double res=dfs(s1,dst,mpp,vis); 
            if(res!=-1) return val*res;
        }
    } 
    return -1.0;
   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>>mpp; 
        for(int i=0;i<equations.size();i++){ 
            string s1=equations[i][0],s2=equations[i][1]; 
            mpp[s1][s2]=values[i]; 
            mpp[s2][s1]=1.0/values[i];
        }
        vector<double>ans; 
        ans.reserve(queries.size()); 
        for(auto it:queries){ 
            string s1=it[0],s2=it[1]; 
            if(mpp.find(s1)==mpp.end() || mpp.find(s2)==mpp.end()) ans.push_back(-1.0); 
            else{ 
                unordered_set<string>vis; 
                double res=dfs(s1,s2,mpp,vis); 
                ans.push_back(res);
            }
        } 
        return ans;
    }
};