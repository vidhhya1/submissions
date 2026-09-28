class Solution {
public: 
vector<string>ans;   
    void f(int i,int n,string digits,string curr,unordered_map<int,string>&mpp){ 
        if(i==n){ans.push_back(curr);return;} 
        string s=mpp[digits[i]-'0']; 
        for(int j=0;j<s.length();j++){ 
            f(i+1,n,digits,curr+s[j],mpp);
        }
    }
    vector<string> letterCombinations(string digits) { 
        if(digits.length()==0) return ans;
        unordered_map<int,string>mpp; 
        mpp[2]="abc";mpp[3]="def";mpp[4]="ghi";mpp[5]="jkl";mpp[6]="mno"; 
        mpp[7]="pqrs";mpp[8]="tuv";mpp[9]="wxyz"; 
        string curr; 
        int n=digits.length(); 
        f(0,n,digits,curr,mpp); 
        return ans;
    }
};
