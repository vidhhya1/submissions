class Solution {
public: 
using ll=long long; 
   bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        ll total=accumulate(matchsticks.begin(),matchsticks.end(),0LL); 
        if(total%4!=0) return false; 
        ll max_el=*max_element(matchsticks.begin(),matchsticks.end());
        if(max_el>(total/4)) return false; 
        sort(matchsticks.rbegin(),matchsticks.rend()); 
        vector<int>dp(1<<n,-1); 
        dp[0]=0;  
        int target=total/4;
        for(int mask=0;mask<(1<<n);mask++){ 
            if(dp[mask]==-1) continue; 
            for(int i=0;i<n;i++){ 
                if((mask&(1<<i))==0 && matchsticks[i]+dp[mask]<=target){ 
                    dp[mask|(1<<i)]=(matchsticks[i]+dp[mask])%target;
                }
            }
        }   
        return dp[(1<<n)-1]==0;
    }
};