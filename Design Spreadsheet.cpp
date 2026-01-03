//https://leetcode.com/problems/design-spreadsheet/description/



class Spreadsheet {
private:
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        sheet.resize(rows+1,vector<int> (26,0));
    }
    
    void setCell(string cell, int value) {
        string t=cell.substr(1);
        sheet[stoi(t)][cell[0]-'A']=value;
    }
    
    void resetCell(string cell) {
        string t=cell.substr(1);
        sheet[stoi(t)][cell[0]-'A']=0;
    }
    
    int getValue(string formula) {
        string a="",b="";
        bool found=0;
        for(int i=0;i<formula.size();i++){
            if(formula[i]=='+') found=1;
            if(found==0){a+=formula[i];}
            else{
                b+=formula[i];
            }
        }
        a=a.substr(1);
        b=b.substr(1);
        int vala=0,valb=0;
        if(a[0]>='0' && a[0]<='9'){
            vala=stoi(a);
        }
        else vala=sheet[stoi(a.substr(1))][a[0]-'A'];
        if(b[0]>='0' && b[0]<='9'){
            valb=stoi(b);
        }
        else valb=sheet[stoi(b.substr(1))][b[0]-'A'];
        return vala+valb;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
