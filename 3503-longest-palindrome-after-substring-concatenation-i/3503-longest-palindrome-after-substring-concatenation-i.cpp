class Solution {
public:
    bool ispal(string n) {
        int l = n.size();
        for (int i=0 ; i<l ; i++){
            if (n[i] == n[l-i-1]){

            }
            else return false;
        }
        return true ;
    }
    int longestPalindrome(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;

        int ans = 1 ;

        for (int i=0 ; i<n ; i++) {
            string p = "" ;
            for (int j=i ; j<n ; j++) {
                p+= s[j];
                if (ispal(p)){
                    ans = max(ans , (int)p.size());
                }
                for (int k = 0 ; k<m ; k++) {
                    string x = "";
                    for (int l=k ; l<m ; l++) {
                        x += t[l] ;
                        if (ispal(x)){
                            ans = max(ans , (int)x.size());
                        }
                        // if (ispal(x+p)){
                        //     ans = max(ans , (int)x.size() + (int)p.size());
                        // }
                        if (ispal(p+x)){
                            ans = max(ans , (int)p.size() + (int)x.size());
                        }

                    }
                }
            }
        } 

        return ans ;


    }
};