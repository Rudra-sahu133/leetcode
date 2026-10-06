class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        int ans = 0;
        while (i < n) {
            if (s[i] == '(') {
                ans++;
            } else {
                ans--;
                if (ans < 0) {
                    cnt++;
                    ans = 0;
                }
            }

            i++;
        }
        if (ans < 0) {
            cnt++;
            ans = 0;
        }
        return ans + cnt;
        // while (i<n && s[i] == ')'){
        //     cnt++;
        //     i++;
        // }
        // int r = n-1;
        // while ( r >=0 && s[r] == '('){
        //     cnt++;
        //     r--;
        // }
        // int ans = 0;
        // while (i<=r ){
        //     if (s[i] == '(') ans++;
        //     else ans--;

        //     i++;
        // }
        // return abs(ans) + cnt ;
    }
};