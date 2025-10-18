//https://leetcode.com/problems/design-an-ordered-stream/description/


class OrderedStream {
private:
    vector<string> order;
    vector<bool> orderDelivered;
    int n;
public:
    OrderedStream(int n) {
        vector<string> o(n,"");
        vector<bool> od(n,false);
        this->order=o;
        this->orderDelivered=od;
        this->n=n;
    }
    
    vector<string> insert(int idKey, string value) {
        order[idKey-1]=value;
        vector<string> make;
        if(idKey-2==-1 || orderDelivered[idKey-2]==true){ //1st order.. or previous order served
            for(int i=idKey-1;i<n;i++){
                if(order[i]!=""){
                    make.push_back(order[i]);
                    orderDelivered[i]=true;
                }
                else{
                    break;
                }
            }
        }
        return make;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
