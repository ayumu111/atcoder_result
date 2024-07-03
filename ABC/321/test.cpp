#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

// 文字列を大文字に変換する関数
string toUpper(string s) {
    for (char& c : s) {
        c = toupper(c);
    }
    return s;
}

bool isAirportCode(string S, string T) {
    int n = S.size();
    int m = T.size();

    for (int i = 0; i < n; i++) {
        S[i] = toupper(S[i]);
    }

    int s = 0;

    for (char c : S) {
        if (c == T[s]) {
            s++;
            if (s == m) {
                return true;
            }
        }
    }

    // Xを追加した場合の判定を追加
    if (s == m - 1 && T[s] == 'X') {
        return true;
    }

    return false;
}

int main() {
    string S, T;
    cin >> S >> T;

    if (isAirportCode(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
