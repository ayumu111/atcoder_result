#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main(){
 string S;
    cin >> S;
   int test = 0; 
   double x = 100;
    for (int i=3; i<6; i++){
        test += (int)(S[i] - '0') * x;
        x = x / 10;
    }
    if (test>0 &&test < 350 && test != 316){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}