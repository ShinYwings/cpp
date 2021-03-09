#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout.precision(3);
    int C;

    cin >> C;

    while(C--){

        int N {0};
        int sum {0};
        float avg {0};
        int highscorer {0};

        cin >> N;

        int *score = new int[N];

        for(int i=0; i < N; ++i){
            cin >> score[i];
            sum += score[i];
        }

        avg = static_cast<float>(sum) / N;

        for(int i=0; i < N; ++i){
            if ( score[i] > avg) highscorer++;
        }

        cout << fixed << (static_cast<float>(highscorer)/N)*100 << "%" << endl;

    }
}