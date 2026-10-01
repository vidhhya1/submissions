class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1; 
        vector<int>dp(n+1,0); 
        for(int i=1;i<=n;i++) dp[i]=i;
        for(int i=3;i<=n;i++){ 
            for(int j=1;2*j<=i;j++){ 
                dp[i]=max(dp[i],dp[j]*dp[i-j]);
            }
        }  
        return dp[n];
    }
};