class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size() ;
        int ans = 0 ;
        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n  ;j++) {
                string k = words[i];
                string k2 = words[j];
                reverse(k2.begin() , k2.end()) ;
                if (k == k2) ans++;
            }
        }

        return ans ;
    }
};