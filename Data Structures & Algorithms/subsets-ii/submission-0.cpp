class Solution {
public: 
    vector<vector<int>>ans; 
    void f(int i,int n,vector<int>&curr,vector<int>&nums){ 
        if(i==n){ans.push_back(curr);return;} 
        curr.push_back(nums[i]);
        f(i+1,n,curr,nums); 
        curr.pop_back(); 
        while(i+1<n && nums[i]==nums[i+1]) i++; 
        f(i+1,n,curr,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>curr; 
        sort(nums.begin(),nums.end()); 
        f(0,n,curr,nums); 
        return ans;
    }
};
