//https://leetcode.com/problems/design-twitter/description/

class Twitter {
private:
    unordered_map<int,unordered_set<int>> follows;
    vector<pair<int,int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        unordered_set<int> f=follows[userId];
        int count=0;
        for(int i=posts.size()-1;i>-1;i--){
            if(f.find(posts[i].first)!=f.end() || userId==posts[i].first){
                result.push_back(posts[i].second);
                if(++count==10) break;
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
