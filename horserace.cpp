//Thank you so much stack overflow
#include <random>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int horseNum = 5;
const int track = 15;

void printLane(const vector<int>& positions) {
    for (int moveCount = 0; moveCount < horseNum; moveCount++) {
        for (int period = 0; period < track; period++) {
            if (positions[moveCount] == period)
                cout << moveCount;
            else
                cout << ".";
        }
        cout << endl;
    }
}


int main() {
    srand(time(0));
    vector<int> positions(horseNum, 0);
    bool keepGoing = false;
    int winner = -1;

    while (!keepGoing) {
        printLane(positions);
        cout << "Press enter for another turn";
        cin.get();

        for (int i = 0; i < horseNum; i++){
            if (rand() % 2 == 1) {
                positions[i]++;
            }
            if (positions[i] >= track - 1) {
                keepGoing = true;
                winner = i;
            }
        } 
    } 

    printLane(positions);
    cout << "Horse " << winner << " is the winner! Congratulations!" << endl;
    return 0;
}