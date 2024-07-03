#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;

    // Declare vectors to store matrices A and B
    vector<vector<char>> A(a, vector<char>(a));
    vector<vector<char>> B(a, vector<char>(a));

    // Input matrix A
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> A[i][j];
        }
    }

    // Input matrix B
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> B[i][j];
        }
    }

    // Compare matrices
    int ansA = -1, ansB = -1;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (A[i][j] != B[i][j]) {
                ansA = i + 1;
                ansB = j + 1;
                break; // Exit the inner loop once a difference is found
            }
        }
        if (ansA != -1) // If a difference is found, exit the outer loop
            break;
    }

    if (ansA == -1 && ansB == -1) {
        cout << "Matrices are identical\n";
    } else {
        cout << ansA << " "<< ansB ;
    }

    return 0;
}
