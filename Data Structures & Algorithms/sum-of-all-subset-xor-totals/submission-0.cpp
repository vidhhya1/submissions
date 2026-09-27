class Solution {
public:  
    int f(int i,int n,vector<int>&nums,int curr_xor){  
        if(i==n) return curr_xor;
    
        return f(i+1,n,nums,curr_xor^nums[i])+f(i+1,n,nums,curr_xor);
        
    }
    int subsetXORSum(vector<int>& nums) {
        return f(0,nums.size(),nums,0);
    }
};