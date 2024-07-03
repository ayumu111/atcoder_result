#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> S(9);
    vector<int> T(8);

    for (int i = 0; i < 9; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < 8; i++) {
        cin >> T[i];
    }

    int sSum = 0;
    int tSum = 0;

    for (int i = 0; i < 9; i++) {
        sSum += S[i];
    }

    for (int i = 0; i < 8; i++) {
        tSum += T[i];
    }

    if (sSum >= tSum) {
        cout << sSum - tSum + 1 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}
