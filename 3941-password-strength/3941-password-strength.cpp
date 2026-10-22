class Solution {
public:
    int passwordStrength(string s) {
        int n = s.size() ;
        int ans = 0 ;
        map<char,int> my;
        for (int i=0 ; i<n ; i++){
            if (my[s[i]] == 1) continue ; 
            if (s[i] >= 'a' &&s[i] <= 'z'){
                ans += 1 ;
                my[s[i]] = 1 ;
            }
            if (s[i] >= 'A' && s[i] <= 'Z'){
                ans += 2 ;
                my[s[i]] = 1 ;
            }
            if (s[i] >= '0' && s[i] <= '9'){
                ans += 3;
                my[s[i]] = 1 ;
            }
            if (s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$'){
                ans += 5;
                my[s[i]] = 1 ;
            }
        }
        return ans ;
    }
};