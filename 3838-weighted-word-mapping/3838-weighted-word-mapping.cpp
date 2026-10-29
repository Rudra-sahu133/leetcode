class Solution {
public:
    string mapWordWeights(vector<string>& w, vector<int>& weights) {
        string ans = "" ;
        int n = w.size() ;
        long long we = 0;
        for (int i=0 ; i<n ; i++) {
            string t = w[i] ;
            we=  0;
            for (int j=0 ; j<t.size() ; j++) {
                we += weights[t[j] - 'a'] ;
            }
            we = we % 26 ;
            we = 25-we ;
            ans += ('a' + we);
        }
        return ans ;
    }
};