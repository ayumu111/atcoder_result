#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


int main(){
double n =64;

int t =0;

while(n >=1){
n= n * 2;
n= n / 3;
t++;
}

cout << t << endl;


}