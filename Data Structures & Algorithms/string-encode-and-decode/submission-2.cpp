class Solution {
public:

    string encode(vector<string>& strs) { 
        string s;
        for(auto it:strs){ 
            s+=to_string(it.size())+'#'+it;
        } 
        return s;
    }

    vector<string> decode(string s) {
         vector<string>ans; 
        int i=0; 
        while(i<s.length()){ 
            int j=i; 
            while(s[j]!='#') j++; 
            int len=stoi(s.substr(i,j-i));  
            string st=s.substr(j+1,len);
            ans.push_back(st); 
            i=j+1+len;
        } 
        return ans;
    }
};
