class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mapi;
        for (char c : secret) {
            mapi[c]++;
        }
        int A = 0;
        string n;
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {

                A++;
                mapi[secret[i]]--;

            } else {
                n += guess[i];
            }
        }
        int B = 0;
        for (char c : n) {
            if (mapi.find(c) != mapi.end()) {
                if (mapi[c] > 0) {
                    B++;
                    mapi[c]--;
                }
            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};