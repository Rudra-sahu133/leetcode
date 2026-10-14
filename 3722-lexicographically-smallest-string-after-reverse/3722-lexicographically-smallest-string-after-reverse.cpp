class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size() ;
        string p = s ;
        sort(p.begin() , p.end()) ;
        int c = 0;
        string ans = s;
        for (int k=1 ; k<=n ; k++){
            string p1 = s ;
            reverse(p1.begin() , p1.begin() + k);
            ans = min(ans , p1);

            p1 = s ;
            reverse(p1.end() - k , p1.end()) ;
            ans = min(ans , p1);
        }
        return ans ;
        
        
    }
};