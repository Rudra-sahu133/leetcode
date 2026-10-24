class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(t.begin() , t.end()) ;
        sort(p.begin() , p.end());
        int n = p.size() ;
        int m = t.size() ;
        int i=0 ; 
        int j= 0 ;
        int ans = 0 ;
        while (i < n && j < m) {
            if (p[i] <= t[j]){
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans ;
        
        
    }
};