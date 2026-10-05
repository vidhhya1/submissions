class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length(); 
        int l=0,r=0; 
        unordered_map<char,int>mpp; 
        int maxf=0,res=0; 
        while(r<n){ 
            mpp[s[r]]++; 
            maxf=max(maxf,mpp[s[r]]); 
            while((r-l+1)-maxf>k){ 
                mpp[s[l]]--;l++;
            }  
            res=max(res,r-l+1);
            r++;
        } 
        return res;
    }
};
