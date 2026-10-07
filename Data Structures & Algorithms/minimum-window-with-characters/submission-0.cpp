class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length(); 
        if(n<m) return "";  
        unordered_map<char,int>mpp; 
        for(char c:t) mpp[c]++; 
        int need=mpp.size(),have=0; 
        int l=0,r=0,start=-1,maxi=INT_MAX; 
        unordered_map<char,int>mpp1; 
        while(r<n){ 
            char c=s[r]; 
            mpp1[c]++; 
            if(mpp[c]==mpp1[c]) have++; 
            while(have==need){ 
                char lc=s[l];  
                if(maxi>(r-l+1)){start=l;maxi=(r-l+1);}
                if(mpp[lc]==mpp1[lc]) {have--;if(--mpp1[lc]==0) mpp1.erase(lc);} 
                l++;
            }
             
            r++;
        } 
        return start==-1?"":s.substr(start,maxi);
    }
};
