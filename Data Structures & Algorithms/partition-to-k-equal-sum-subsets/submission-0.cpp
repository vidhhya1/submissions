class Solution {
public: 
   vector<int>dp; 
   int target,n; 
    bool dfs(int mask,vector<int>&nums){ 
        if(mask==0) return 0; 
        if(dp[mask]!=INT_MIN) return dp[mask]; 
        for(int i=0;i<n;i++){ 
            if((mask&(1<<i))){ 
                int res=dfs(mask^(1<<i),nums); 
                if(res>=0 && res+nums[i]<=target){ 
                    dp[mask]=(res+nums[i])%target; 
                    return dp[mask];
                } 
                if(mask==(1<<n)-1) {dp[mask]=-1;return -1;}
            }
        } 
        dp[mask]=-1;
        return -1;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size(); 
        int total=accumulate(nums.begin(),nums.end(),0); 
        if(total%k!=0) return false;  
        sort(nums.rbegin(),nums.rend()); 
        target=total/k; 
        if(nums[0]>target) return 0; 
        dp.assign(1<<n,INT_MIN); 
        return (dfs((1<<n)-1,nums)==0);
    }
};