class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(); 
        unordered_map<char,int>mpp; 
        int maxlen=0,left=0,right=0; 
        while(right<n){ 
           if(mpp.find(s[right])!=mpp.end()){ 
              left=mpp[s[right]]+1;
           } 
           mpp[s[right]]=right; 
           maxlen=max(maxlen,right-left+1); 
           right++;
        } 
        return maxlen;
    }
};
