class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size() ;
        map<char , stack<int> > my;
        long long ans = 0 ;
        for (int i= 0 ; i<n ; i++){
            char mr = char(25 - (s[i] - 'a') + 'a') ;
            if (my.find(mr) != my.end()){
                if (my[mr].size() > 0){
                    ans += abs(i - my[mr].top());
                    my[mr].pop();
                }
                else {
                    my[s[i]].push(i);
                }
            }
            else {
                my[s[i]].push(i);
            }
        }
        return ans ;
    }
};