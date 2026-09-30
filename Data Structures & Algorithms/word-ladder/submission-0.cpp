class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {       if(beginWord==endWord) return 0;
        unordered_set<string>st(wordList.begin(),wordList.end()); 
        if(st.count(endWord)==0) return 0; 
        queue<string>q; 
        int level=1;  
        q.push(beginWord);
        while(!q.empty()){ 
            int sz=q.size(); 
            for(int k=0;k<sz;k++){ 
                string s=q.front();q.pop(); 
                if(s==endWord) return level;
                for(int i=0;i<s.length();i++){ 
                    char org=s[i]; 
                    for(char c='a';c<='z';c++){ 
                        if(c==org) continue; 
                        s[i]=c; 
                        if(st.count(s)){ q.push(s); 
                            st.erase(s); 
                        }
                    } 
                    s[i]=org;
                }
            } 
            level++;
        } 
        return 0;
    }
};
