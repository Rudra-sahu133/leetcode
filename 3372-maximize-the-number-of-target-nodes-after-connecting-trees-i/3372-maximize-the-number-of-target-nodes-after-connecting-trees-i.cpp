class Solution {
public:
    int bfs(vector<vector<int>>& adj , int i , int k , vector<int> &vis){
        queue<pair<int,int>> q;
        q.push({i,0});
        vis[i] = 1 ;
        int ans = 0;
        while (!q.empty()){
            int node = q.front().first;
            int l = q.front().second;
            q.pop();
            if (l <= k) ans++;
            for (auto it : adj[node]){
                if (vis[it] == 0){
                    vis[it] = 1;
                    q.push({it , l+1});
                }
                
            }
        }
        return ans ;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1 ;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1 (n );
        for (int i=0 ; i<edges1.size() ; i++) {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }

        vector<vector<int>> adj2 (m  );
        for (int i=0 ; i<edges2.size() ; i++) {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        vector<int> a(n , 0);
        vector<int> b(m , 0);
        
        vector<int> vis2(m, 0);
        for (int i=0 ; i<n ; i++) {
            vector<int> vis(n , 0);
            a[i] = bfs(adj1 , i , k , vis);
            
        }
        int mx = -1 ;
        for (int i =0 ; i<m ; i++){
            vector<int> vis(m , 0);
            b[i] = bfs(adj2 , i , k-1 , vis);
            mx = max(mx , b[i] );
        }

        for (int i=0 ; i<n ; i++){
            a[i] += mx ;
        }
        return a ;





    }
};