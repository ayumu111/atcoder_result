#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> w(n);
    vector<int> Max(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

   

    for (int i = 0; i < n; i++) {
       a[i]--;
       Max[a[i]] = max(Max[a[i]], w[i]);
    }

    const int sum_w=accumulate(w.begin(),w.end(),0);
    const int sum_max=accumulate(Max.begin(),Max.end(),0);

    cout << sum_w-sum_max << endl;
    return 0;
}
