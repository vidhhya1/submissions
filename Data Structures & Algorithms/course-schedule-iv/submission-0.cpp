class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
     vector<vector<bool>>pre(n,vector<bool>(n,false));
        for(auto it:prerequisites){ 
            pre[it[0]][it[1]]=true;
        }  
        for(int k=0;k<n;k++){ 
            for(int i=0;i<n;i++){ 
                for(int j=0;j<n;j++){ 
                    if(pre[i][k]&&pre[k][j]){ 
                        pre[i][j]=true;
                    }
                }
            }
        } 
        vector<bool>ans; 
        ans.reserve(queries.size());     
        for(auto q:queries){ 
            ans.push_back(pre[q[0]][q[1]]);
        }
        return ans;
    }
};