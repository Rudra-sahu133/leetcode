class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<char> vec(n, 'f');

        int j = 0;

        while (j < n) {

            if (s[j] == 'L') {
                vec[j] = 'L';

                int p = j;

                while (p - 1 >= 0 && s[p - 1] == '.' && vec[p - 1] == 'f') {
                    vec[p - 1] = 'L';
                    p--;
                }
            }

            else if (s[j] == 'R') {

                int cnt = 0;
                int p = j;

                while (p + 1 < n && s[p + 1] == '.') {
                    cnt++;
                    p++;
                }

                bool f = false;

                if (p + 1 < n && s[p + 1] == 'L') {
                    f = true;
                }

                if (f) {

                    if (cnt % 2 == 0) {
                        cnt = cnt / 2;

                        while (j + 1 < n && s[j + 1] == '.' && cnt > 0) {
                            vec[j + 1] = 'R';
                            j++;
                            cnt--;
                        }
                    }

                    else {
                        cnt = cnt / 2;

                        while (j + 1 < n && s[j + 1] == '.' && cnt > 0) {
                            vec[j + 1] = 'R';
                            j++;
                            cnt--;
                        }

                        vec[j + 1] = 'T';
                    }
                }

                else {
                    while (j + 1 < n && s[j + 1] == '.') {
                        vec[j + 1] = 'R';
                        j++;
                    }
                }
            }

            j++;
        }

        for (int i = 0; i < n; i++) {
            if (vec[i] == 'f') {
                vec[i] = s[i];
            }
            else if (vec[i] == 'T') {
                vec[i] = '.';
            }
        }

        string ans = "";

        for (auto it : vec) {
            ans += it;
        }

        return ans;
    }
};