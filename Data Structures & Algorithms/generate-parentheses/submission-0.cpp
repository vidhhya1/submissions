class Solution {
public: 
    vector<string>ans; 
    void f(int o,int c,int n,string curr){
        if(o==n && c==n){ans.push_back(curr);return;}  
        if(o<n) f(o+1,c,n,curr+'('); 
        if(o>c) f(o,c+1,n,curr+')'); 
    }
    vector<string> generateParenthesis(int n) {
        string curr; 
        f(0,0,n,curr); 
        return ans;
    }
};
