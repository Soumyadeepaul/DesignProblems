//https://leetcode.com/problems/design-a-stack-with-increment-operation/description/


class CustomStack {
private:
    vector<int> stack;
    int l;
    int i=-1;
public:
    CustomStack(int maxSize) {
        l=maxSize;
    }
    
    void push(int x) {
        if(i+1<l){
            i++;
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(i==-1){return -1;}
        int popped=stack[i];
        stack.pop_back();
        i--;
        return popped;
    }
    
    void increment(int k, int val) {
        for(int j=0;j<min(k,i+1);j++){
            stack[j]+=val;
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
