class Solution {
public:
    bool solve(string s1, string s2, string s3) {
        if (s1.empty() && s2.empty() && s3.empty())
            return true;
        if (!s1.empty() && s2.empty() && s3.empty())
            return false;
        if (s1.empty() && !s2.empty() && s3.empty())
            return false;
        if (s1.empty() && s2.empty() && !s3.empty())
            return false;

        bool take=false;
        bool noti=false;
        if(s1[0]==s3[0] && s2[0]==s3[0]){
            take=solve(s1.substr(1),s2, s3.substr(1));
            noti=solve(s1,s2.substr(1),s3.substr(1));
        }
        else if(s1[0]==s3[0] && s2[0]!=s3[0]){
            take=solve(s1.substr(1),s2, s3.substr(1));
        }
        else if(s1[0]!=s3[0] && s2[0]==s3[0]){
             noti=solve(s1,s2.substr(1),s3.substr(1));
        }
        else{
            return false;
        }
        return take || noti;
    }
    bool isInterleave(string s1, string s2, string s3) {
      return   solve(s1, s2, s3);
    }
};