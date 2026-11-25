class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int> , vector<pair<float,int>>> pq;
        int n = points.size();
        for(int i =0; i< k;i++){
            float dist = sqrt(points[i][1]*points[i][1] + points[i][0]*points[i][0]);
            pq.push({dist, i});
        }

        for(int i = k;i<n;i++){
            float dist = sqrt(points[i][1]*points[i][1] + points[i][0]*points[i][0]);
            if(dist < pq.top().first){
                pq.pop();
                pq.push({dist, i});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            ans.push_back(points[front.second]);
        }
        return ans;
    }
};
