#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll t;
    cin >> n >> t;
    string s;
    cin >> s;
    vector<ll> x1, x2;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (s[i] == '1')
            x1.push_back(x);
        else
            x2.push_back(x);
    }
    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    int l = 0, r = 0;
    ll ans = 0;
    for (int i = 0; i < (int)x1.size(); ++i) {
        while (l < (int)x2.size() && x2[l] < x1[i]) l++;
        while (r < (int)x2.size() && x2[r] <= x1[i] + 2 * t) r++;
        ans += r - l;
    }
    cout << ans << '\n';
}
