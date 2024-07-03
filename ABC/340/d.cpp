#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// カスタムコンパレータ
struct CompareByValue {
    bool operator()(const std::pair<int, long long>& a, const std::pair<int, long long>& b) const {
        return a.second > b.second; // 値で比較
    }
};

int main() {

    int n;
    cin >> n;
    vector<int> a(n-1);
    vector<int> b(n-1);
    vector<int> x(n-1);
    vector<int> d(n);

    for(int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i) >> x.at(i);
    }
    // カスタムコンパレータを使用してpriority_queueを定義
    priority_queue<pair<int, long long[]>, vector<std::pair<int, long long>>, CompareByValue> pq;

    d[0] = 0; 
     
    // 要素の挿入
   for(int i = 0; i <= n; i++) {
        pq.push(std::make_pair(i, d[i]));
    }





    // プライオリティキューから要素を取り出す
    while (!pq.empty()) {
        pair<int, long long> p = pq.top();
        pq.pop();
        int v = p.first;
        long long d = p.second;
        if (d > ) continue;
    }

    return 0;
}
