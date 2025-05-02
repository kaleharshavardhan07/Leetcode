class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        // vector<int> r(n, -1);
        vector<int> l(n, -1);
        int le = -1;
        for (int i = n - 1; i >= 0; i--) {

            if (dominoes[i] == 'L') {
                le = i;
                l[i] = 0;
            } else if (dominoes[i] == 'R') {
                le = -1;
            } else {
                if (le != -1)
                    l[i] = le - i;
            }
        }
        int re = -1;
        // string s = "";
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
               dominoes[i]= 'R';
                re = i;
            } else if (dominoes[i] == 'L') {
                re = -1;
                dominoes[i]='L';
            } else {
                if (dominoes[i] == '.') {
                    int t = i - re;
                    if (l[i] != -1 && re != -1) {
                        if (l[i] > t) {
                            dominoes[i]= 'R';
                        } else if (l[i] < t) {
                            dominoes[i]= 'L';
                        } else {
                            dominoes[i]= '.';
                        }
                    } else if (l[i] == -1 && re != -1) {

                        dominoes[i]= 'R';

                    } else if (l[i] != -1 && re == -1) {
                        dominoes[i]= 'L';
                    } else {
                       dominoes[i]= '.';
                    }
                }
            }
        }

        return dominoes;
    }
};