#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define REP(i, n) for (int i = 1; i <= int(n); i++)

template <class F>
inline constexpr decltype(auto) lambda_fix(F&& f) {
    return [f = forward<F>(f)](auto&&... args) {
        return f(f, forward<decltype(args)>(args)...);
    };
}
template <class T>
constexpr void printArray(const vector<T>& vec, char split = ' ') {
    rep(i, vec.size()) {
        cout << vec[i];
        cout << (i == (int)vec.size() - 1 ? '\n' : split);
    }
}
int N;
vector<int> vec[100010], ans;
int flag[100010];
int main() {
    cin >> N;
    rep(i, N - 1) {
        int A, B;
        cin >> A >> B;
        vec[A].emplace_back(B);
        vec[B].emplace_back(A);
    }
    lambda_fix([&](auto self, int node, bool f) -> void {
        flag[node] = f + 1;
        for (int i : vec[node]) {
            if (!flag[i]) self(self, i, !f);
        }
    })(1, false);
    if (count(flag + 1, flag + N + 1, 1) >= N / 2) {
        REP(i, N) {
            if (flag[i] == 1) ans.emplace_back(i);
            if (ans.size() == N / 2) break;
        }
        printArray(ans, ' ');
    } else {
        REP(i, N) {
            if (flag[i] == 2) ans.emplace_back(i);
            if (ans.size() == N / 2) break;
        }
        printArray(ans);
    }
    return 0;
}