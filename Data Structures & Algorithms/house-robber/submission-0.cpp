class Solution {
public:
    int rob(vector<int>& nums) { 
        int n=nums.size();
        vector<pair<int,int>>dp(n); 
        dp[0]={nums[0],0}; 
        for(int i=1;i<n;i++){ 
            int t=nums[i]+dp[i-1].second; 
            int nt=max(dp[i-1].first,dp[i-1].second); 
            dp[i]={t,nt};
        } 
        return max(dp[n-1].first,dp[n-1].second);
    }
};
