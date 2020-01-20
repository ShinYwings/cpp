#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class dtime{

    private:
        int start;
        int end;
    
    public:
        int getStart() const { return start; }
        int getEnd() const { return end; }
        void setStart(int t) { start = t; }
        void setEnd(int t) { end = t; }
        
    dtime(){ this->start =0;
             this->end = 0;
             };
};

vector<dtime> discuss;

bool compare(dtime a, dtime b){

    if ( a.getEnd() == b.getEnd() )
        return a.getStart() < b.getStart();

    return a.getEnd() < b.getEnd();
}

int main()
{
    int N {0};

    cin >> N;

    for(int i {0}; i<N; ++i){

        int start, end;
        dtime d;

        cin >> start >> end;

        d.setStart(start);
        d.setEnd(end);

        discuss.push_back(d);

    }

    sort(discuss.begin(), discuss.end(), compare);

    int count {0};
    int current = {0};

    
    for(int i {0}; i<discuss.size(); ++i){
    
        if ( current <= discuss.at(i).getStart() ){

            current = discuss.at(i).getEnd();        
            count++;
        }
        
    }

    cout << count << endl;

    return 0;


}