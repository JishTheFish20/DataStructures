#include <iostream>
#include "TimeSupport.h"
#include "RandomSupport.h"
#include "ArrayList.h"

using namespace std;



int main(){

    const int N = 100000;
    int totalTime;

    for(int x = 0; x < 10; x++){
        ArrayList<int> arr;
        RNG rng(1, N * 10);
        timestamp start = current_time();

        for (int i = 0; i < N; i++){
            int num = rng.get();
            arr.add(num);

            for (int j = 0; j < N; j++){
                arr.search(-1);
            }
        }

        timestamp end = current_time();

        int duration = time_diff(start, end);

        totalTime += duration;

        cout << "Took " << duration << " ms." << endl;
    }

     cout << "Total Average Time Took " << totalTime/10 << " ms." << endl;

    return 0;
}