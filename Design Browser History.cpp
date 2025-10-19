//https://leetcode.com/problems/design-browser-history/description/

class BrowserHistory {
private:
    vector<string> history;
    int idx=-1;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        idx++;
    }
    
    void visit(string url) {
        for(int i=history.size()-1;i>idx;i--){
            history.pop_back();
        }
        history.push_back(url);
        idx++;
    }
    
    string back(int steps) {
        if(idx<steps){
            idx=0;
        }
        else{
            idx-=steps;
        }
        return history[idx];
    }
    
    string forward(int steps) {
        if(history.size()-idx-1<=steps){
            idx=history.size()-1;
        }
        else{
            idx+=steps;
        }
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
