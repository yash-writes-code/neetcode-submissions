class Solution {
public:
    bool DFS(int node,unordered_map<int, vector<int>> &adj,vector<int> &visited, vector<int>& inRecursion , int par){

        
        //cycle detected
        //cout<<"DFS AT INDEX :"<<node<<", making as visited"<<endl;
        visited[node] =1;
        inRecursion[node]=1;
        bool res = true;

        for(auto nei : adj[node]){
            //cout<<"neighbor of node : "<<node<<" is:"<<nei<<" as nei is visited?"<<visited[nei]<<endl;
            if(visited[nei] && inRecursion[nei] && par!= nei) return false;
            if(!visited[nei]){
                res = res && DFS(nei, adj, visited, inRecursion,node);
            }
        }
        inRecursion[node] = 0;
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //all nodes are connected
        //there are no cycles

        //single DFS will iterate the complete graph
        //and find cycles if present
        if(edges.size() == 0) return true;
        unordered_map<int, vector<int>> adj;

        for(const auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        //cout<<"size : "<<adj.size();
        vector<int> visited(adj.size(),0);
        vector<int> inRecursion(adj.size(),0);
        
        if(!DFS(0,adj, visited, inRecursion,-1)) return false;
        for(int i =1;i<adj.size();i++){
            if(!visited[i]){
              //cout<<"node index : "<<i<<" is not visited"<<endl;
              return false;  
            } 
        }

        return true;
    }
};
