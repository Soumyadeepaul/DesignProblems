//https://leetcode.com/problems/design-an-atm-machine/description/


class ATM {
private:
    unordered_map<int,int> notes;
    vector<int> curr={20,50,100,200,500};
public:
    ATM() {
        for(int c:curr) notes[c]=0;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            notes[curr[i]]+=banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> used(5, 0);

        // traverse from largest note to smallest
        for (int i = 4; i >= 0; i--) {
            int note = curr[i];

            if (notes[note] > 0) {
                int take = min(amount / note, notes[note]);
                used[i] = take;
                amount -= take * note;
            }
        }

        if (amount != 0) return {-1};

        // update ATM storage
        for (int i = 0; i < 5; i++) {
            notes[curr[i]] -= used[i];
        }

        return used;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
