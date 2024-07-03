#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    int idx1 = 0;
    int idx2 = 0;
string S = string();
cin >> S;
for(int i = 0; i < 3; i++){
    if(S[i] == 'R'){
    idx1 = i;
    }
    if(S[i]== 'M'){
        idx2 = i;
    }

}

if(idx1< idx2){
    cout << "Yes" << endl;
}
else{
    cout << "No" << endl;
}







}
