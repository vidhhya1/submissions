class Solution {
public: 
using ll=long long; 
    bool f(int i,int n,vector<int>&sides,vector<int>&matchsticks){ 
        if(i==n) return sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]; 
        for(int j=0;j<4;j++){ 
            sides[j]+=matchsticks[i]; 
            if(f(i+1,n,sides,matchsticks)) return true; 
            sides[j]-=matchsticks[i];
        } 
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();
        ll total=accumulate(matchsticks.begin(),matchsticks.end(),0LL); 
        if(total%4!=0) return false; 
        ll max_el=*max_element(matchsticks.begin(),matchsticks.end());
        if(max_el>(total/4)) return false; 
        vector<int>sides(4,0);
        return f(0,n,sides,matchsticks);
        
    }
};