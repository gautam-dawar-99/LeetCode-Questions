// problem link : https://leetcode.com/problems/my-calendar-i/
class MyCalendar {
public:
 vector<pair<int,int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
           for(auto it:vec)   {
            if(it.second>start && it.first<end){
                return false;
            }
        }

        vec.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */