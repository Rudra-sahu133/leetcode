class Solution {
public:
    bool isValid(string s) {
        int n = s.size() ;
        int c = 0;
        int s1 = 0;
        int p = 0;
        stack<char> st;
        for (int i=0 ; i<n ; i++){
            if (s[i] == '(') {
                st.push('(') ;
            }
            if (s[i] == '{'){
                st.push('{') ;
            }
            if (s[i] == '[') {
                st.push('['); 
            }
            if (s[i] == ')'){
                if (st.size() > 0) {
                    if (st.top() == '('){   
                        st.pop() ;
                    }
                    else return false;
                }
                else return false;
            }
            else if (s[i] == '}'){
                if (st.size() > 0) {
                    if (st.top() == '{'){
                        st.pop() ;
                    }
                    else return false;
                }
                else return false;
            }
            else if (s[i] == ']'){
                if (st.size() > 0){
                    if (st.top() == '['){
                        st.pop() ;
                    }
                    else return false;
                }
                else return false;
            }
        } 
        if (st.size() > 0) return false;
        return true ;
        // for (int i=0 ; i<n ; i++) {
        //     if (s[i] == '('){
        //         p++;
        //     }
        //     else if (s[i] == ')'){
        //         p--;
        //         if (p < 0) return false;
        //     }
        //     if (s[i] == '{'){
        //         c++;
        //     }
        //     else if (s[i] == '}'){
        //         c--;
        //         if (c < 0) return false;
        //     }
        //     if (s[i] == '['){
        //         s1++;
        //     }
        //     else if (s[i] == ']'){
        //         s1--;
        //         if (s1 < 0) return false;
        //     }
        // }
        // return true ;
    }
};