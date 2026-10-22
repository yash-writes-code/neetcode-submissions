class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, vector<pair<int,int>>> adj;
        //u->{v,w}
        for(const auto &t: times){
            adj[t[0]].push_back({t[1],t[2]});
          
        }

        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;

        int max_dis = INT_MIN;

        pq.push({0,k});

        while(!pq.empty()){
            auto [d,node] = pq.top();
            pq.pop();
            if(dis[node] < d) continue;
            if(node != k) max_dis = max(max_dis,d);
            for(auto [next , wt] : adj[node]){
                if(dis[next] > d + wt){
                    dis[next] = d + wt;
                    pq.push({dis[next],next});
                }
            }
        }
        for(int i =1;i<n+1;i++){
            if(dis[i] == INT_MAX) return -1;
        }
        return max_dis;
    }
};
