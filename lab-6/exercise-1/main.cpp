#include <iostream>
#include "GoodList.h"
#include "TimeSupport.h"
#include "ArrayList.h"

using namespace std;



int main(){

    const int N = 5000000;

    GoodList goodList;
    ArrayList<int> arrayList;


    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        goodList.append(i);
    }

    cout << goodList << endl;

    timestamp end = current_time();

    int alDuration = time_diff(start, end);

    cout << "Array List: " << alDuration << " ms." << endl;

    return 0;
}