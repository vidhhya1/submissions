class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         unordered_map<string,vector<string>>mpp; 
         for(auto it:tickets){ 
            mpp[it[0]].push_back(it[1]);
         } 
         for(auto& it:mpp){ 
            sort(it.second.rbegin(),it.second.rend());
         } 
         stack<string>st;st.push("JFK"); 
         vector<string>ans; 
         while(!st.empty()){ 
            string s=st.top(); 
            if(mpp[s].empty()){ 
                ans.push_back(s); 
                st.pop();
            } 
            else{ 
                st.push(mpp[s].back()); 
                mpp[s].pop_back();
            }
         } 
         reverse(ans.begin(),ans.end()); 
         return ans;
    }
};
