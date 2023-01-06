#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;


int main(){

    Queue<int> times;
    Queue<string> names;

    int jobCount;
    cin >> jobCount;

    for (int i = 0; i < jobCount; i++){
        string name;
        int time;
        cin >> name;
        cin >> time;

        cout << name << " : " << time << endl;
        times.enqueue(time);
        names.enqueue(name);
    }

    int period;
    cin >> period;
    cout << "---THIS IS THE TIME SHEET---" << endl << endl;
    while (times.length() > 0){
        if((times.peek() - period) > 0){
            cout << names.peek() << " : " << period << endl;
            times.enqueue(times.peek() - period);
            names.enqueue(names.peek());

            times.dequeue();
            names.dequeue();
        }else{
            cout << names.peek() << " : " << times.peek() << endl;
            times.dequeue();
            names.dequeue();
        }
    }



    // Output round robin schedule, where person can use machine for no longer than the set period

    cout << "Done..." << endl;

    return 0;
}