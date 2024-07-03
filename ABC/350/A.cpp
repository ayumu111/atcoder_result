#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    char a, b, c;
    cin >> a >> b >> c;
    vector<char> S{'A', 'B', 'C', a, b, c};
    for (int i = 0; i < 6; i++) {
        cout << S[i] << endl;
    }
    int test = 0;
    double x = 100; // floatまたはdoubleに変更
    for (int i = 3; i < 6; i++) {
        test += (int)(S[i]- '0') * x; // char型をint型にキャストするのではなく、ASCIIコード値をそのまま使う
        cout << test << endl;
        x = x / 10;
    }

    if (test < 350 && test != 316) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
