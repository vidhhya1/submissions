class Solution {
public:

    string encode(vector<string>& strs) { 
        string s;
        for(auto it:strs){ 
            s+=it+' ';
        } 
        return s;
    }

    vector<string> decode(string s) {
         vector<string>ans; 
         stringstream ss(s);  
         string word;
         while(getline(ss,word,' ')){ 
            ans.push_back(word);
         }
         return ans;
    }
};
