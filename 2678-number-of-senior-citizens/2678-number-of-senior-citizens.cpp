#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        
        for (const string& s : details) {
           
            string ageStr = s.substr(11, 2);
            
            
            int age = stoi(ageStr);
            
         
            if (age > 60) {
                count++;
            }
        }
        
        return count;
    }
};
