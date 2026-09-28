class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length(); 
        int i=0,j=n-1; 
        while(i<j){ 
            while(i<j && !isalpha(s[i])) i++; 
            while(i<j && !isalpha(s[j])) j--; 
            if(i<j && tolower(s[i])!=tolower(s[j])) return false; 
            i++;j--;
         } 
         return true;
    }
};
