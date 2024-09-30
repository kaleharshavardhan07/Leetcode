class CustomStack {
public:
    int size;
    vector<int>st;
    int curr;

    CustomStack(int maxSize) {
       this->size=maxSize;
       this->curr=-1; 
        st.resize(maxSize);
    }
    
    void push(int x) {
        if( curr<size-1){
            
            curr++;
                        st[curr] = x;
            
        }

    }
    
    int pop() {
        if( curr>=0){
            int val= st[curr];
            curr--;
            return val;

        }
        return -1;
    }
    
    void increment(int k, int val) {
        for( int i=0;i<min(curr+1,k);i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */