class MyCalendar {
    set<pair<int, int>> bookings;

    bool doesIntersectWithNeighBours(int start, int end) {
        auto nextBooking = bookings.lower_bound({start, end});
        return (nextBooking != bookings.end() && nextBooking->first < end) || 
            (nextBooking != bookings.begin() && start < prev(nextBooking)->second);
    }
public:
    bool book(int start, int end) {
        if (doesIntersectWithNeighBours(start, end)) return false;
        bookings.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */