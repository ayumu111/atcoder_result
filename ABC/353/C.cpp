#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
     long long   sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
      if (A[i] < 10000000 && i == 0){
        sum = sum;
        } // Add an else if here
        else if (A[i] < 100000000 && i != 0 && A[i-1]<100000000){
        sum += A.at(i) + A.at(i-1);
        }
        else if (A[i] >= 100000000 && i != 0 && A[i-1] >= 100000000){
        sum += (A.at(i)%100000000) + (A.at(i-1)%100000000);
        }
        else if (A[i] >= 100000000 && i != 0 && A[i-1] < 100000000){
        sum += (A.at(i)%100000000) + A.at(i-1);
        }

        
    }
   
    
  cout << sum << endl;
}
