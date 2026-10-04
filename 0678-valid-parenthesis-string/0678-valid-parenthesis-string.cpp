class Solution {
public:
    int arr[101][101];

    bool fun(int i, int l, string &s) {
        int n = s.size();

        if (l < 0)
            return false;

        if (i == n) {
            return l == 0;
        }

        if (arr[i][l] != -1)
            return arr[i][l];

        if (s[i] == '(') {
            return arr[i][l] = fun(i + 1, l + 1, s);
        }
        else if (s[i] == ')') {
            return arr[i][l] = fun(i + 1, l - 1, s);
        }
        else {
            return arr[i][l] =
                fun(i + 1, l + 1, s) ||
                fun(i + 1, l - 1, s) ||
                fun(i + 1, l, s);
        }
    }

    bool checkValidString(string s) {
        memset(arr, -1, sizeof(arr));

        return fun(0, 0, s);
    }
};