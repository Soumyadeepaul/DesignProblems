//https://leetcode.com/problems/design-a-number-container-system/description/


class NumberContainers {
private:
    unordered_map<int,int> map;
    unordered_map<int,unordered_set<int>> helper;
    unordered_map<int,int> storeMin;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(map.count(index)){
            helper[map[index]].erase(index);
            if(helper[map[index]].size()==0){
                helper.erase(map[index]);
                storeMin.erase(map[index]);
            }
            else{
                if(storeMin[map[index]]==index)
                    storeMin[map[index]]=*min_element(helper[map[index]].begin(),helper[map[index]].end());   
            }
        }
        map[index]=number;
        helper[number].insert(index);
        if(storeMin.count(number)){
            storeMin[number]=min(storeMin[number],index);
        }
        else{
            storeMin[number]=index;
        }
    }
    
    int find(int number) {
        if(storeMin.count(number))
            return storeMin[number];
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
