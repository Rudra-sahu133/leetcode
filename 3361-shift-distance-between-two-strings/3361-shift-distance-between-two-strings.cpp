class Solution {
public:

    long long shiftDistance(string s, string t, vector<int>& nextcost,
                            vector<int>& previouscost) {
        int n = s.size();
        long long cnt = 0 ;
        for (int i = 0; i < n; i++) {
            int idx1 = s[i] - 'a';
            int idx2 = t[i] - 'a';
            long long ans1 = 0;
            int j = (idx1) ;
            while (true) {
                if (j != idx2) {
                    ans1 += 0LL + nextcost[j];
                    j = (j + 1) % 26;
                } else {
                    
                    break;
                }
            }

            j = (idx1);
            long long ans2 = 0;
            while (true) {
                if (j != idx2){
                    ans2 += 0LL + previouscost[j] ;
                    j = (j -1 + 26) % 26 ; 
                }
                else {
                    
                    break;
                }
            }

            cnt += min(ans1 , ans2) ;



        }
        return cnt ;
    }
};