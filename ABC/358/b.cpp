#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> T(N);
    vector<int> X(N);

    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
    }

    for (int i = 0; i < N; i++) {
        if (i == 0 || T.at(i) >= X.at(i-1)) {
            X.at(i) = T.at(i) + A;
        } else {
            X.at(i) = X.at(i-1) + A;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << X.at(i) << endl;
    }

    return 0;
}
