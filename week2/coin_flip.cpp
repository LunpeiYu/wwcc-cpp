#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    cout << "Simulating " << flips << " coin flips " << endl;

    for (int i = 0; i < flips; i++) {
        int coin = rand() % 2;
        if (coin == 0) {
            heads++;
        } else {
            tails++;
        }
    }

    double Heads_Percent = double(heads) / flips * 100;
    double Tails_Percent = double(tails) / flips * 100;

    cout << fixed << setprecision(2);

    cout << "\nResults:" << endl;
    cout << "Heads:" << heads <<" (" << Heads_Percent << "%)" << endl;
    cout << "Tails:" << tails <<" (" << Tails_Percent << "%)" << endl;

    return 0;
}