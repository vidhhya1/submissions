
class Solution { 
    struct Trie{ 
    Trie* child[26]={nullptr}; 
    bool isend=false;
}; 
void insert(Trie* root,string s){ 
    Trie* curr=root; 
    for(auto c:s){ 
        int idx=c-'a'; 
        if(!curr->child[idx]){curr->child[idx]=new Trie();} 
        curr=curr->child[idx];
    }
    curr->isend=true;
}
public:
    bool wordBreak(string s, vector<string>& wordDict) { 
        int n=s.length();
        Trie* root=new Trie(); 
        for(auto st:wordDict){ 
            insert(root,st);
        }  
        vector<bool>dp(n+1,false);
        dp[0]=true; 
        for(int i=0;i<n;i++){  
            if(!dp[i]) continue; 
            Trie* curr=root;
            for(int j=i;j<n;j++){ 
                 int idx=s[j]-'a'; 
                 if(!curr->child[idx]) break; 
                 curr=curr->child[idx];
                 if(curr->isend)dp[j+1]=true;
            }
        } 
        return dp[n];
    }
};
