class Solution {
public:
    vector<int> ret(string num1) {
        int flag = 0;
        string s1;
        string s2;
        for (char s : num1) {
            if (s != '+' && flag == 0) {
                s1 += s;
            } else if (s != '+' && flag == 1) {
                s2 += s;
            } else {
                flag = 1;
            }
        }

        
        s2.pop_back();
        
        int a = stoi(s1);
        int b = stoi(s2);
        return {a, b};
    }

    string complexNumberMultiply(string num1, string num2) {
        vector<int> cmp1 = ret(num1);
        vector<int> cmp2 = ret(num2);

       
        int real = (cmp1[0] * cmp2[0]) - (cmp1[1] * cmp2[1]);
        int imag = (cmp1[0] * cmp2[1]) + (cmp1[1] * cmp2[0]);

        
        string r = to_string(real) + '+' + to_string(imag) + 'i';
        return r;
    }
};
