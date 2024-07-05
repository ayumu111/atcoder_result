#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    ll A, B, C;
    cin >> A >> B >> C;

    int ans = 10000; // 9999よりも大きな初期値に設定

    for (int i = 0; i <= 9999; i++) {
        for (int j = 0; j <= 9999 - i; j++) {
            ll k = A * i + B * j;
            if (k > N) {
                break; // kがNを超えた場合はループを抜ける
            }
            if ((N - k) % C == 0) {
                int c = (N - k) / C;
                ans = min(ans, i + j + c);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
