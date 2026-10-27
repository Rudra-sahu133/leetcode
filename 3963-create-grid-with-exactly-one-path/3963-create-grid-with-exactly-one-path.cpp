class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> vec ;
        for (int i = 0 ; i<m-1 ; i++) {
            string p = "." ;
            for (int i=1 ; i<n ; i++) {
                p += '#';
            }
            vec.push_back(p);
        }
        string  p = "";
        for (int i=0 ; i<n ; i++) {
            p += '.';
        }
        vec.push_back(p) ;
        return  vec ;
    }
};