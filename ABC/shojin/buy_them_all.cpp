#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main(){
 int N,X;
    cin >> N >> X;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        if((i+1) % 2 == 1){
            A.at(i)--;
        }
        sum += A.at(i);
    }
    if(sum <= X){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}