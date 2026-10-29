class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n = words.size() ;
        map<string , int> my;
        for (int i=0 ; i<n ; i++) {
            if (words[i].size() >= k){
                string p = "" ;
                for (int j=0 ; j<k ; j++) {
                    p += words[i][j] ;
                }
                my[p]++;
            }
        }
        int ans = 0 ;
        for (auto it : my) {
            if (it.second >= 2){
                ans++;
            }
        }
        return ans ;
    }
};