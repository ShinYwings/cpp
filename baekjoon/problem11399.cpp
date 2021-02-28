#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class dtime{

    private:
        int due;
    
    public:
        int getDue() const { return due; }
        void setDue(int t) { due = t; }
        
    dtime(){ this->due =0;
             };
};

bool compare(dtime a, dtime b){
    return a.getDue() < b.getDue();
}

int main()
{
    int N {0};

    vector<dtime> discuss;

    cin >> N;

    for(int i {0}; i<N; ++i){

        int due;
        dtime d;

        cin >> due;

        d.setDue(due);

        discuss.push_back(d);

    }

    sort(discuss.begin(), discuss.end(), compare);

    int count {0};
    int total {0};

    for(int i {0}; i<discuss.size(); ++i){
    
            count += discuss.at(i).getDue();
            total += count;
        
    }

    cout << total << endl;

    return 0;


}