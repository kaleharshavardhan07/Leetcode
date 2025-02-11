class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        // int i=0;
        // while(i< s.length()){
        //     if(s.length()<part.length()){
        //         break;
        //     }
        //     string temp=s.substr(i,part.length());
        //     if(temp==part){
        //         s.erase(i,part.length());
        //         if(i>0){
        //             i--;
        //         }
        //     }
        //     else{
        //         i++;
        //     }
        // } 
         size_t pos = s.find(part);  
    while (pos != std::string::npos) {
        s.erase(pos, part.length());  
        pos = s.find(part); 
    }
    return s;
        
    }
};