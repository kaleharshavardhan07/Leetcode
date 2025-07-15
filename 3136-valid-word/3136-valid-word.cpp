class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        int nf = 0;
        int cf = 0;
        int vf = 0;
        int cap = 0;
        int sm = 0;

        for (char c : word) {
            int f = 0;
            if (c > 47 && c < 58) {
                nf = 1;
                f = 1;
            }
            if (c > 64 && c < 91) {
                cap = 1;
                f = 1;
                if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    vf = 1;

                else
                    cf = 1;
            }
            if (c > 96 && c < 123) {
                sm = 1;
                f = 1;

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    vf = 1;

                else
                    cf = 1;
            }
            if (f == 0)
                return false;
        }

        if( cf && vf && ( sm ||cap) )return true;

        return false;
    }
};