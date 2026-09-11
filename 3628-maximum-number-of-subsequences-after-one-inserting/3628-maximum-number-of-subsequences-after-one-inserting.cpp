
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        int c = 0;
        vector<int> pf(n) ;
        if (s[0] == 'L'){
            pf[0] = 1 ;
        }
        else {
            pf[0] = 0;
        }
        for (int i=1 ; i<n; i++) {
            if (s[i] == 'L'){
                pf[i] = 1 + pf[i-1];
            }
            else {
                pf[i] = pf[i-1];
            }
        }
        vector<int> sf(n);
        if (s[n-1] == 'T'){
            sf[n-1] = 1 ;
        }
        else {
            sf[n-1] = 0;
        }
        for(int i=n-2 ; i>=0 ; i--) {
            if (s[i] == 'T'){
                sf[i] = 1+ sf[i+1] ;
            }
            else {
                sf[i] = sf[i+1] ;
            }
        }

        long long ans1 = 0 ;
        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'C'){
                ans1 += ((pf[i]+1)*1LL) * (sf[i] * 1LL);
            }
        }
        long long ans2 =0 ;
        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'C'){
                ans2 += ((pf[i])*1LL) * ((sf[i]+1) * 1LL);
            }
        } 
        long long ans3 = 0 ;
        long long mx = 0 ;
        for (int i=0 ; i<n; i++){
            if (s[i] == 'C'){
                ans3 += (1LL*pf[i])*(sf[i]*1LL) ;
                c++;
            }
            mx = max(mx , (1LL*pf[i])*(sf[i] * 1LL)) ;
        }
        if (c == 0){
            ans3 = mx ;
        }
        else {
            ans3 += mx ;

        }
        

        return max(ans1 , max(ans2,ans3)) ;
    }
};