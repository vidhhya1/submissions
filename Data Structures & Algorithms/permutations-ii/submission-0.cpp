class Solution {
public: 
    vector<vector<int>>ans; 
    void f(int start,int n,vector<int>&nums){ 
        if(start==n){ans.push_back(nums);return;} 
        for(int i=start;i<n;i++){ 
            if(i!=start && nums[i]==nums[start]) continue; 
            swap(nums[i],nums[start]); 
            f(start+1,n,nums); 
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size(); 
        f(0,n,nums); 
        return ans;
    }
};