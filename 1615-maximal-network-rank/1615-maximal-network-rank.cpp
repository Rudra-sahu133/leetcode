class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> vec(n , vector<int> (n,0)) ;
        for (int i=0 ; i<roads.size() ; i++){
            vec[roads[i][0]][roads[i][1]] = 1;
            vec[roads[i][1]][roads[i][0]] = 1;
        }
        vector<int> arr(n,  0);
        for (int i=0 ; i<roads.size() ;i++){
            arr[roads[i][0]]++;
            arr[roads[i][1]]++;
        }
        int ans = 0;
        for(int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++){
                ans = max(ans , arr[i] + arr[j] + (vec[i][j] == 1 ? -1 : 0)) ; 
            }
        }
        return ans ;
    }
};