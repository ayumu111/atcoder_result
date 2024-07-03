#include <iostream>
#include <vector>
using namespace std;

int main(){
    int Q;
    cin >> Q;
    vector<vector<int>> que(2, vector<int>(Q));
    vector<int> x;

    for(int i = 0; i < Q; i++) {
        cin >> que.at(0).at(i) >> que.at(1).at(i);
    }

    for(int i = 0; i < Q; i++) {
        if(que.at(0).at(i) == 1) {
            x.push_back(que.at(1).at(i));
        } else if(que.at(0).at(i) == 2) {
            int k = que.at(1).at(i) - 1; // Convert to zero-based index
            if(k < static_cast<int>(x.size())) {
                cout << x.at(x.size() - k - 1) << endl; // Access the correct element
            } else {
                cout << "Error: Index out of range" << endl; // Optional error handling
            }
        }
    }

    return 0;
}
