class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int r = 0;
        int c = 0;
        vis[0][0] = 1;
        while (true) {
            if (grid[r][c] == 'R') {
                if (c + 1 < n && vis[r][c + 1] == 0) {
                    r = r;
                    c = c + 1;
                    vis[r][c] = 1;
                } else
                    break;
            }
            if (grid[r][c] == 'L') {
                if (c - 1 >= 0 && vis[r][c - 1] == 0) {
                    r = r;
                    c = c - 1;
                    vis[r][c] = 1;
                } else
                    break;
            }
            if (grid[r][c] == 'U') {
                if (r - 1 >= 0 && vis[r - 1][c] == 0) {
                    r = r - 1;
                    c = c;
                    vis[r][c] = 1;
                } else
                    break;
            }
            if (grid[r][c] == 'D') {
                if (r + 1 < m && vis[r + 1][c] == 0) {
                    r = r + 1;
                    c = c;
                    vis[r][c] = 1;
                } else
                    break;
            }
        }
        return {r,c};

        // for (int i=0 ; i<m ; i++) {
        //     for (int j=0 ; j<n ; j++) {
        //         if (grid[i][j] == 'R'){
        //             if (j+1 < n && vis[i][j+1] == 0){
        //                 r = i ;
        //                 c = j+1;
        //                 vis[i][j+1] = 1 ;
        //             }
        //             else return {r,c};
        //         }
        //         if (grid[i][j] == 'L'){
        //             if (j-1 >= 0 && vis[i][j-1] == 0){
        //                 r= i ;
        //                 c = j-1;
        //                 vis[i][j-1] = 1 ;
        //             }
        //             else return {r,c};
        //         }
        //         if (grid[i][j] == 'U'){
        //             if (i-1 >=0 && vis[i-1][j] == 0){
        //                 r = i-1 ;
        //                 c= j ;
        //                 vis[i-1][j] = 1 ;
        //             }
        //             else return {r,c};
        //         }
        //         if (grid[i][j] == 'D' ){
        //             if (i+1 < n && vis[i+1][j] == 0){
        //                 r = i+1 ;
        //                 c=  j;
        //                 vis[i+1][j] = 1 ;
        //             }
        //             else return {r,c};
        //         }
        //     }
        // }
        // return {r,c};
    }
};