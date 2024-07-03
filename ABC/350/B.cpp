#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    // 初期状態でランプがすべて点灯していると仮定
    vector<int> H(N, 1);
    
    vector<int> T(Q);
    for (int i = 0; i < Q; i++) {
        cin >> T[i];
        // スイッチの番号に対応するランプの状態を切り替える
        H[T[i] - 1] = 1 - H[T[i] - 1]; // 対応するランプの状態を反転させる
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += H[i]; // 点灯しているランプの数をカウント
    }
    
    cout << sum << endl;
    return 0;
}
