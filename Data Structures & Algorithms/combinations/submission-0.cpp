class Solution {
public:
    vector<vector<int>>ans; 
    void f(int i,int k,int n,vector<int>&res){  
        if(res.size()==k){ans.push_back(res);return;}
        if(res.size()>k|| i>n) return; 
        res.push_back(i); 
        f(i+1,k,n,res); 
        res.pop_back();
        f(i+1,k,n,res);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>res; 
        f(1,k,n,res); 
        return ans;
    }
};