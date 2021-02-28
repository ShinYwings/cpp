#include <iostream>

using namespace std;

typedef enum days{SUN, MON, TUE, WED, THU, FRI, SAT} days;

inline days operator++(days d){
    return static_cast<days>((static_cast<int>(d)+1 % 7));
}


// C++11 에서 바뀐 enum definition  (타입을 지정할 수 있게 됨)
enum class WierdLogic : unsigned {
    NO,         // 0
    MAYBE=5, 
    YES=10
};  // a yes is worth 2 maybe's

ostream& operator<< (ostream& out, const days& d){ // call by reference
    switch(d){
        case SUN: out<< "SUN"; break;
        case MON: out<< "MON"; break;
        case TUE: out<< "TUE"; break;
        case WED: out<< "WED"; break;
        case THU: out<< "THU"; break;
        case FRI: out<< "FRI"; break;
        case SAT: out<< "SAT"; break;
    }

    return out;
}

int main()
{
    days d = MON, e; // days d = MON; days e;
    e = ++d;
    cout << d << '\t' << e << endl;
}