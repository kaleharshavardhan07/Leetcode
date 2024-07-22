class MapSum {
public:
    map<string,int>mapi;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mapi[key]=val;
    }
    
    int sum(string prefix) {
        int l=prefix.length();
        int sum=0;
        for(auto it: mapi){
            string c= it.first;
            c=c.substr(0,l);
            if(c==prefix){
                sum=sum+it.second;
            }


        }
        return sum;
        
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */