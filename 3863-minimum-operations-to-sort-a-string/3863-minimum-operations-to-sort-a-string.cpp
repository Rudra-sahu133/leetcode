class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if ( n == 1 ) return 0;
        if ( n == 2 && s[0] > s[1]) return -1;
        if (n == 2) return 0 ;
        string p = s ;
        sort(p.begin() , p.end()) ;
        if (p == s) return 0 ;

        if (s[0] == p[0] && s[n-1] == p[n-1] ){
           return 1 ;
        }
        else if ( s[0] == p[0] && s[n-1] != p[n-1]){
            return 1;
        }
        else if (s[0] != p[0] &&s[n-1] == p[n-1]){
            return 1 ;
        }
        else {
            int ans1 = 0;
            string t = s ;
            if (t != p) {
                sort(t.begin() , t.end() -1) ;
                ans1++;
                
            }
            if (t != p){
                sort(t.begin() + 1 , t.end());
                ans1++;
            }
            if (t != p){
                ans1++;
            }

            int ans2 = 0;
            if (s != p){
                sort(s.begin()+1 , s.end()) ;
                ans2++;
            }
            if (s != p){
                sort(s.begin() , s.end() -1) ;
                ans2++;
            }
            if (s != p) ans2++;

            return min(ans1 , ans2) ;
            
            
        }
        return -1 ;
    }
};