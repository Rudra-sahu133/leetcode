class Solution {
public:
    
    
    int totalNumbers(vector<int>& digits) {
        int n = digits.size() ;
        int p = 0 ;
        int q = 0;
        int cnt = 0;

        for (int i=100 ; i<= 999 ; i++) {
            vector<int> hash(10 , 0);
            for (auto it : digits){
                hash[it]++;
            }
            bool f = true ;
            if (i % 2 == 0){
                int k = i;
                while (k){
                    if (hash[k % 10] > 0){
                        hash[k% 10]--;
                    }
                    else {
                        f = false;
                    }
                    k = k  / 10 ;
                }

                if (f) cnt++;
            }
            
        }
        return cnt ;

    }
};