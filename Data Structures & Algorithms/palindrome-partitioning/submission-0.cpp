class Solution {
public: 
    vector<vector<string>>ans;  
    bool palindrome(string st){ 
        int i=0,j=st.length()-1; 
        while(i<j){ 
            if(st[i++]!=st[j--]) return false;
        } 
        return true;
    }
    void f(int start,int n,string s,vector<string>&curr,vector<vector<string>>&ans){ 
        if(start==n){ans.push_back(curr);return;} 
        string st;
        for(int i=start;i<n;i++){ 
            st+=s[i]; 
            if(palindrome(st)){ 
                curr.push_back(st); 
                f(i+1,n,s,curr,ans); 
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length(); 
        vector<string>curr; 
        f(0,n,s,curr,ans); 
        return ans;
    }
};
