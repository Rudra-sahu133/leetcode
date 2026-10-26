class Solution {
public:
    long long sum = 0;

bool dfs(int i, int j, int m, int n,
         vector<vector<int>>& grid,
         vector<vector<int>>& vis, int k1) {

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vis[i][j] = 1;
    sum += grid[i][j];

    for (int k = 0; k < 4; k++) {
        int newx = i + dx[k];
        int newy = j + dy[k];

        if (newx >= 0 && newx < m &&
            newy >= 0 && newy < n &&
            grid[newx][newy] > 0 &&
            vis[newx][newy] == 0) {

            dfs(newx, newy, m, n, grid, vis, k1);
        }
    }

    return sum % k1 == 0;
}
    int countIslands(vector<vector<int>>& grid, int k1) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<int>> vis(m , vector<int> (n , 0)) ;
        int ans = 0;
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (!vis[i][j] && grid[i][j] > 0){
                    sum = 0;
                    ans += (true == dfs(i , j , m , n , grid , vis , k1));
                }
            }
        }
        return ans ;

    }
};