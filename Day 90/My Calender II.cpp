// problem link : https://leetcode.com/problems/my-calendar-ii/
class MyCalendarTwo {
    vector<pair<int, int>> s;
    vector<pair<int, int>> d;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int st, int ed) {
        for(auto i: d) {
            if(max(i.first, st) < min(i.second, ed))
                return false;
        }

        for(auto i: s) {
            if(max(i.first, st) < min(i.second, ed))
                d.push_back({max(i.first, st), min(i.second, ed)});
        }

        s.push_back({st, ed});
        return true;
    }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */