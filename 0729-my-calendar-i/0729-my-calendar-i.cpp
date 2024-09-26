class Booking {
    int start;
    int end;
public:
    Booking(int startt, int endd) {
        start = startt;
        end = endd;
    }

    int getStart() { return start; }

    int getEnd() { return end; }
};

class MyCalendar {
    vector<Booking> bookings;

    bool doesIntersect(Booking booking, int start, int end) {
        return booking.getStart() < end && start < booking.getEnd();
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (Booking &booking : bookings) 
            if (doesIntersect(booking, start, end)) return false;
        bookings.push_back(Booking{start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */