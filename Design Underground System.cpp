//https://leetcode.com/problems/design-underground-system/description/


class UndergroundSystem {
private:
    unordered_map<int, pair<string,int>> track;
    unordered_map<string, unordered_map<string, pair<long long,int>>> mp; //start : end : {time,count}

public:
    void checkIn(int id, string stationName, int t) {
        track[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [start, time] = track[id];
        track.erase(id);

        mp[start][stationName].first += (t - time); // total time
        mp[start][stationName].second++;           // count
    }

    double getAverageTime(string startStation, string endStation) {
        auto &p = mp[startStation][endStation];
        return (double)p.first / p.second;
    }
};
