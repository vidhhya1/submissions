class Solution {
public: 
    vector<vector<int>>ans; 
    void f(int i,int n,int target,vector<int>&nums,vector<int>&res){ 
       
        if(target==0){ 
            ans.push_back(res);return;
        }  
         if(i==n || target<0) return;  
        if(nums[i]<=target){ 
            res.push_back(nums[i]); 
            f(i,n,target-nums[i],nums,res); 
            res.pop_back();
        } 
        f(i+1,n,target,nums,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>res;  
        int n=nums.size(); 
        sort(nums.begin(),nums.end());
        f(0,n,target,nums,res); 
        return ans;
    }
};
