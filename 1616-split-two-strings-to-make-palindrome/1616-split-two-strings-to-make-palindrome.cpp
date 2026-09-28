class Solution {
public:
    bool pal(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool check(string &a, string &b, int l, int r) {
        while (l < r && a[l] == b[r]) {
            l++;
            r--;
        }

        return pal(a, l, r) || pal(b, l, r);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b, 0, a.size() - 1) ||
               check(b, a, 0, a.size() - 1);
    }
};