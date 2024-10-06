class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string a, b;

        if (sentence1.length() > sentence2.length()) {
            a = sentence1;
            b = sentence2;
        } else {
            a = sentence2;
            b = sentence1;
        }

        vector<string> a1;
        vector<string> b1;

        stringstream ss_a(a);
        string word;
        while (ss_a >> word) {
            a1.push_back(word);
        }

        stringstream ss_b(b);
        while (ss_b >> word) {
            b1.push_back(word);
        }

        int a_size = a1.size();
        int b_size = b1.size();
        
        int i = 0, j = 0;

        while (i < b_size && a1[i] == b1[i]) {
            i++;
        }

        while (j < b_size && a1[a_size - j - 1] == b1[b_size - j - 1]) {
            j++;
        }

        return i + j >= b_size;
    }
};
