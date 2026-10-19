class Solution {
public:
    int DFS(int i, int j , vector<vector<int>> &grid,vector<vector<int>> &visited ){
        visited[i][j]=1;

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        int area = 1;

        for(int d=0;d<4;d++){
            int new_i= i + dy[d];
            int new_j = j + dx[d];

            if(new_i <0 || new_i >=grid.size() || new_j<0 || new_j>=grid[0].size()){
                continue;
            }
            else if(grid[new_i][new_j] == 0 || visited[new_i][new_j] == 1) {continue;}
            else area+= DFS(new_i,new_j,grid, visited); 
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j =0;j<m ;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    maxArea = max(maxArea, DFS(i,j,grid,visited));
                }
            }
        }
        return maxArea;
    }
};
