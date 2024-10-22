class Solution {
public:
    string removeStars(string s) {
        string result;  

        for (char ch : s) {
            if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            } else {
                result.push_back(ch);
            }
        }

        return result;
    }
};



// BY MISTAKE I THI=OUGHT I WANT TO DELETE AADJ LEFT OR RIGHT SO MADE IT 
// class Solution {
// public:
//     string removeStars(string s) {
//         int i = 0;
//         int prev=0;
//         while (i < s.length()) {
//             if (s[i] == '*') {
                
//                 int r = i;
//                 int temp;

                
               
//                 temp=prev;
//                 while (r < s.length() && r-i<i-prev) {
//                     if (s[r] != '*')
//                       temp=r;
//                         break;
//                     r++;
//                 }
//                 prev--;

//                 s.erase(i, 1);
//                 s.erase(temp, 1);
//                 i--;

//                 if (i < 0)
//                     i = 0;
//             } else {
//                 prev=i;
//                 i++;
//             }
//         }
//         return s;
//     }
// };