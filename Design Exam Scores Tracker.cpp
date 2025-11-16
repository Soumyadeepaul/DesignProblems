//https://leetcode.com/problems/design-exam-scores-tracker/description/

//TLE

class ExamTracker {
private:
    vector<pair<int,int>> tracker;
public:
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        tracker.push_back({time,score});
    }
    
    long long totalScore(int startTime, int endTime) {
        //binary search
        //find searchTime
        if(startTime>endTime) return 0;
        pair<int,int> idx={-1,-1};
        int start=0;
        int end=tracker.size();
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            if(tracker[mid].first==startTime) { 
                idx.first=mid;
                break;
            }
            else if (tracker[mid].first>startTime) {
                idx.first=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        if(startTime!=endTime){
            start=idx.first;
            end=tracker.size();
            //find end time
            while(start<=end){
                mid=start+(end-start)/2;
                if(tracker[mid].first==endTime) { 
                    idx.second=mid;
                    break;
                }
                else if (tracker[mid].first<endTime) {
                    idx.second=mid;
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        else{
            if(idx.first>-1 && idx.first<tracker.size() && tracker[idx.first].first>endTime){
                return 0;
            }
            else    idx.second=idx.first;
        }
        long long result=0;
        for(int i=idx.first;i<=idx.second;i++) result=(long long) result+tracker[i].second;
        return result;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
