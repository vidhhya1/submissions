class Solution {
public: 
    vector<vector<int>>ans;   
    void f(int i,int n,vector<int>&res,vector<int>&nums){ 
        if(i==n){ ans.push_back(res);return;} 
        res.push_back(nums[i]); 
        f(i+1,n,res,nums); 
        res.pop_back(); 
        f(i+1,n,res,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>res; 
        f(0,nums.size(),res,nums); 
        return ans;
    }
};
