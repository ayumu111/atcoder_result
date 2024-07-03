#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
int N,M;
cin >> N >> M;
vector<vector<string>> A(N, vector<string>(M));
vector<int> B(N);
int ans = 0;
int res = 0;

for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        cin >> A.at(i).at(j);
        if(A.at(i).at(j) == "o"){
            B.at(i)++;
        }
    }
}










    while(true){
         int i,j;

         if(A.at(i).at(j) == "o"){
            ans++;
            i++;}
         else if(A.at(i).at(j) == "x"){
            i++;}
        
         if(ans !=M && i == N){
            i = 0;           
        }   


        

        if(ans == M){
            break;


        }

    }
      








}









