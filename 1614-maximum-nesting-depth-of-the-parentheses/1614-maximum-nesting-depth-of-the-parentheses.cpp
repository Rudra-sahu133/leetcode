class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        
        for (int i=0 ; i<n ; i++){
            if (s[i] == '('){
                l++;
                ans = max(ans , l);
            }
            if (s[i] == ')'){
                l--;
            }
        }
        return ans ;
    }
};