class Solution {
public:
    bool MakeEdge(string &w1, string &w2,  unordered_map<int,vector<int>> &adj){
        //if w2 is prefix of w1 return false

        int p1 = 0;
        int p2 = 0;

        while(p1<w1.size() && p2<w2.size()){
            if(w1[p1] != w2[p2]) {
                adj[w1[p1]-'a'].push_back(w2[p2]-'a');
                return true;
            }
            else{
                p1++;
                p2++;
            }
        }

        if(p2 == w2.size() && p1 < w1.size()) return false;
        return true;

    }

    bool TopoExists(unordered_map<int,vector<int>> &adj, string &res,unordered_set<char> &chars){
            vector<int> indegree(26,0);

            for(auto &item : adj){
                for(auto elem : item.second) indegree[elem]++;
            }

            queue<int> q;
            for(int i=0;i<26;i++){
                if(indegree[i] == 0 && chars.find(i+'a')!=chars.end()) q.push(i);
            }

            if(q.empty()) return false;

            while(!q.empty()){
                auto top = q.front();
                q.pop();
                res+=top+'a';

                for(auto nei: adj[top]){
                    indegree[nei]--;
                    if(indegree[nei] == 0) q.push(nei);
                }
            }
            if(res.size() == chars.size()) return true;
            return false;

    }
    string foreignDictionary(vector<string>& words) {
        unordered_map<int,vector<int>> adj;

        unordered_set<char> chars;

for (const string& word : words) {
    for (char c : word) {
        chars.insert(c);
    }
}
        for(int i =0;i<words.size()-1 ; i++){
            auto w1 = words[i];
            auto w2 = words[i+1];

            if(!MakeEdge(w1,w2,adj)) return "";
        }

        //topo sort
        string res="";
        if(!TopoExists(adj,res,chars)) return "";
        return res;
    }
};
