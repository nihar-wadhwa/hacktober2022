// User function Template for C++

class Solution {
  private:
        int dirx[4]={-1, 0, 1, 0};
        int diry[4]={0, 1, 0, -1};
    public:
        int numberOfEnclaves(vector<vector<int>> &grid) {
            // Code here
            int n=grid.size(), m=grid[0].size();
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int countLand=0;
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    if(grid[i][j]==1){
                        ++countLand;
                        if(isBoundary(i,j, n, m) && !vis[i][j]){
                            int visLand=0;
                            dfs(i, j, n, m, grid, vis, visLand);
                            countLand-=visLand;
                        }
                    }
                }
            }
            return countLand;
        }
        
        bool isBoundary(int i, int j, int n, int m){
            if(i==n-1 || j==m-1 || i==0 || j==0) return true;
            return false;
            
        }
        
        void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>>& vis, int& visLand){
            vis[i][j]=true;
            ++visLand;
            for(int k=0; k<4;++k){
                int newi=i+dirx[k];
                int newj=j+diry[k];
                if(newi>=0 && newi<n && newj>=0 && newj<m && !vis[newi][newj] && grid[newi][newj]==1){
                    dfs(newi, newj, n, m, grid, vis, visLand);
                }
            }
        }
};
