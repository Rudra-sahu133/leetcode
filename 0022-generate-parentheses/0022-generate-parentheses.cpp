class Solution {
public:
int N;
   vector<string> arr;

    void fun(int l , int r , string s ) {
        if (s.size()==2*N){
            arr.push_back(s) ;
            return ;
        }
        if (l <N) {
           
            fun (l+1, r  , s+'(') ;
        }
        if(r<l){
            
           
                fun (l , r+1,  s +')');
            }
            
           

    
    }
    vector<string> generateParenthesis(int n) {
        N=n;
     
       
        fun (0, 0, "") ;
        return arr ;
    }
};