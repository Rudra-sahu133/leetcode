class Solution {
public:
    vector<string> validStrings(int n) {
        
        vector<string> vec ;
        if (n == 1){
            vec.push_back("0");
            vec.push_back("1");
            return vec ;
        }
        for (int i=0 ; i< (1<<n) ; i++) {
            int k = i ;
            string s = "" ;
            while (k){
                if (k % 2 == 0) {
                    s += '0';
                }
                else s+= '1';

                k =k / 2 ;
            }

            reverse(s.begin() , s.end() );
            if (s.size() < n){
                int rem = n - s.size() ;
                while (rem){
                    s = '0' + s;
                    rem--;
                }
            }
            bool f = true;
            for (int i=0 ; i<n-1 ; i++){
                if (s[i] == '0' && s[i+1] == '0') f =false;
            }

            if (f) vec.push_back(s) ;

        }
        return vec ;
    }
};