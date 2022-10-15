#include <iostream>
#include <time.h>
using namespace std;
#define ARRAYSIZE 100

int headOfQueue = 0;
int endOfQueue = 0;
int arr[ARRAYSIZE];

void enqueue(int key) {
    if (headOfQueue == endOfQueue) {
        arr[headOfQueue] = key;
    }
    else {
        arr[endOfQueue] = key;
    }
    endOfQueue++;

}
void dequeue() {
    arr[headOfQueue] = NULL;
    headOfQueue++;
}

void findTheOrder(int prediction) {
    bool exist = 1;
    while (headOfQueue < ARRAYSIZE) {
        if (arr[headOfQueue] == prediction) {
            cout << endl;
            cout << "Number " << "(" << prediction << ")" << " found at " << (headOfQueue + 1) << ". place.";
            cout << endl;
            exist = 1;
            break;
        }
        else {
            dequeue();
            exist = 0;
        }
    }
    if (exist == false) {
        cout << endl;
        cout << "The number that you try to find does not exist in queue.";
        cout << endl;
    }
}


int main() {
    srand(time(NULL));

    int prediction;

    cout << "Enter your guess: ";
    cin >> prediction;

    for (int i = 0; i < ARRAYSIZE; i++) {
        int number = (rand() % 1000);
        enqueue(number);
    }
    //SAYILARIN SIRASINI GÖRMEK İÇİN
    /*
    for(int j=0;j<ARRAYSIZE;j++){
            cout << j+1 << ". " << array[j] <<endl;
    }
    */

    findTheOrder(prediction);



    return 0;
}
