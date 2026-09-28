class Solution {
public: 
    vector<vector<int>>ans; 
    void f(int i,int n,int target,vector<int>&candidates,vector<int>&res){ 
       
        if(target==0){ 
            ans.push_back(res);return;
        }  
         if(i==n || target<0) return;  
        if(candidates[i]<=target){ 
            res.push_back(candidates[i]); 
            f(i+1,n,target-candidates[i],candidates,res); 
            res.pop_back();
        }  
        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
            i++;
        }
        f(i+1,n,target,candidates,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>res;  
        int n=candidates.size(); 
        sort(candidates.begin(),candidates.end());
        f(0,n,target,candidates,res); 
        return ans;
    }
};
