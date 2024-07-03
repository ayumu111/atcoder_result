#include <iostream>
#include <algorithm>
using namespace std;
constexpr int INF = 1000000000;
int N, Q, A[300010];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int B;
        cin >> B;
        int ans = INF;
        auto p = upper_bound(A, A + N, B);
        if (p != A + N) ans = min(ans, *p - B);
        if (p != A) ans = min(ans, B - *prev(p));
        cout << ans << endl;
    }
    return 0;
}