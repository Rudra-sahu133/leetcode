class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size() ;
        int cnt = 0;
        int i=0 ;
        set<string> st ;
        while (i<n) {
            if (isalpha(word[i])) {
                i++;
            }
            else {
                string s = "";
                while(i<n && word[i] == '0'){
                    i++;
                }
                bool f = false;
                while ( i<n && isdigit(word[i])){
                    s += word[i];
                    i++;
                    f=true;
                }
                if (!f){
                    st.insert("0");
                }
                else st.insert(s);
            }
        }
        return st.size() ; 
    }
};