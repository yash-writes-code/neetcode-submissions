class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>(0,0));
        vector<int> indegree(numCourses,0);

        for(auto const & e: prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q;
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            auto course = q.front();
            q.pop();
            res.push_back(course);
            for(int i=0;i<adj[course].size();i++){
                if(--indegree[adj[course][i]] == 0) q.push(adj[course][i]);
            }
        }

        if(res.size() != numCourses) return {};
        else return res;
    }
};
