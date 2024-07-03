#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K = 0;
    int N;

    cin >> N;
    
    vector<int> A(N);
    vector<int> pos(N); // pos配列を初期化
    vector<pair<int, int>> steps;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        pos[A[i] - 1] = i+1; // A[i] の位置を pos 配列に保存
    }

    for (int i = 0; i < N; ++i) {
       
        if(i != pos[i]){
            swap(A[i], A[pos[i]-1]);
            K++;
            steps.push_back(make_pair(i, pos[i]-1)); 
        }
       
        
    }
    K++;
    cout << K << endl;
    for (int i = 0; i < steps.size(); ++i) {
        cout << steps[i].first << " " << steps[i].second << endl;
    }
}

