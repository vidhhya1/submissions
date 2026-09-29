class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> inDegree(numCourses, 0);
        
        // Build the graph (note: if u is a prereq of v, edge is u -> v)
        for (const auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }
        
        // prereqs[i] stores a bitmask of all courses that are prerequisites of course i
        // Max numCourses is 100 based on constraints
        std::vector<std::bitset<100>> prereqs(numCourses);
        std::queue<int> q;
        
        // Push all nodes with 0 in-degree into the queue
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process graph topologically
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                // Course 'u' is a direct prerequisite of 'v'
                prereqs[v].set(u);
                // Inherit all of course 'u's prerequisites into 'v' using bitwise OR
                prereqs[v] |= prereqs[u];
                
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Answer each query in O(1)
        std::vector<bool> answer;
        answer.reserve(queries.size());
        for (const auto& query : queries) {
            answer.push_back(prereqs[query[1]].test(query[0]));
        }
        
        return answer;
    }
};