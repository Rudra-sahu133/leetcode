class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k1) {
        int n= s.size() ;
        map<string , int> my ;
        int k = n / k1 ;
        for (int i=0 ; i<n ; i+=k){
            string p = "";
            for (int j=i ; j<i+k ; j++){
                p += s[j];
            }
            my[p]++;
        }
        for (int i=0 ; i<n ; i+=k){
            string p = "";
            for (int j=i ; j<i+k ; j++){
                p += t[j];
            }
            my[p]--;
        }
        bool f = true ;
        for (auto it : my) {
            if (it.second != 0){
                return false;
            }
        }
        return true ;

    }
};