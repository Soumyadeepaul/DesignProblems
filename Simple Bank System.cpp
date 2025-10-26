//https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26


class Bank {
private:
    unordered_map<int,long long> accounts;
public:
    Bank(vector<long long>& balance) {
        cout<<balance.size();
        for(int i=1;i<=balance.size();i++){
            accounts[i]=balance[i-1];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>accounts.size()||account2>accounts.size()) return false;
        if(accounts[account1]>=money){
            accounts[account1]-=money;
            accounts[account2]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>accounts.size()) return false;
        accounts[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>accounts.size()) return false;
        if(accounts[account]>=money){
            accounts[account]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
