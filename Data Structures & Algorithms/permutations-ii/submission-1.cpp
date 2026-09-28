class Solution {
public: 
    vector<vector<int>>ans; 
    void f(int start,int n,vector<int>&nums){ 
        if(start==n){ans.push_back(nums);return;}  
        unordered_set<int>st;
        for(int i=start;i<n;i++){ 
            if(st.count(nums[i])) continue; 
            st.insert(nums[i]);
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