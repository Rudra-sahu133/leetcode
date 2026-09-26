class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> my;
        for (int i=0 ; i<knowledge.size() ; i++){
            my[knowledge[i][0]] = knowledge[i][1];
        }
        int n = s.size();
        int i=0 ; 
        string ans = "" ;
        while (i<n) {
            if (isalpha(s[i])) {
                ans += s[i];
                i++;
                continue;
            }
            if (s[i] == '(') {
                string p = ""; 
                i++;
                while(s[i] != ')'){
                    p+= s[i];
                    i++;
                }
                i++;
                if (my.find(p) != my.end()){
                    ans += my[p];
                }
                else{
                    ans += '?';
                }
            }
        }
        return ans ;
    }
};