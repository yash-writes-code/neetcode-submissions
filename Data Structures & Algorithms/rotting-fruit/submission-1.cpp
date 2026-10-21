class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time =0 , FreshFruits=0;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        //r,c

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) FreshFruits++;
                else if(grid[i][j] ==2) q.push({i,j}); 
            }
        }

        if(FreshFruits ==0) return time;

        while(!q.empty()){
            int rottenFruits = q.size();

            for(int i=0;i<rottenFruits;i++){
                auto [r,c] = q.front();
                q.pop();

                vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};

                for(auto &d : dirs){
                    int new_r = r + d.first;
                    int new_c = c + d.second;

                    if(new_r <0 || new_r >=n || new_c<0 || new_c >=m) continue;
                    else if(grid[new_r][new_c] != 1) continue;
                    else {
                        grid[new_r][new_c] =2;
                        FreshFruits--;
                        q.push({new_r, new_c});
                    }
                }

            }
            time++;
        }

        return (FreshFruits ==0)? time-1 : -1;
    }
};
