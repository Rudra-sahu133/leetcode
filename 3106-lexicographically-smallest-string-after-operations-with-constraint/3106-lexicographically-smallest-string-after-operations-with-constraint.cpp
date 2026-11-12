class Solution {
public:
    string getSmallestString(string s, int k) {
        string t = "" ;
        int n = s.size() ;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<26 ; j++) {
                int df = min(abs(s[i] - ('a' + j)) , 26 - (abs(s[i] - ('a' + j)))) ;
                if (df <= k){
                    k = k - df ;
                    t += char('a' + j) ;
                    break;
                }
                
            }
        }
        return t ; 
    }
};