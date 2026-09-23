class Solution {
public:
    bool closeStrings(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size() ;
        if (n1 != n2){
            return false;
        }
        vector<int> hash1(26, 0 ) , hash2(26,0) ;
        for (int i=0 ; i<n1 ; i++){
            hash1[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        for (int i=0 ; i<26 ; i++) {
            if (hash1[i] == 0 && hash2[i] > 0) return false;
            if (hash2[i] == 0 && hash1[i] > 0) return false;
        }
        sort(hash1.begin() , hash1.end());
        sort(hash2.begin() , hash2.end());
        for (int i =0 ; i<26 ; i++) {
            if (hash1[i] == hash2[i]){

            }
            else {
                return false;
            }
        }
        return true ;


    }
};