#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){

    long long N,K;
    cin >> N >> K;
    vector<ll> Temp(N+1);

if(N>=K){
    for(int i=0; i<K; i++){
        Temp[i] = 1;
    }

    Temp[K]= K;

    for(int i =K+1; i < N+1; i++){
        Temp[i] = Temp[i-1] * 2 - Temp[i-K-1];
        Temp[i] %= 10000000000;
    }

    cout << Temp[N]%1000000000 << endl;
}else{
    

    cout << 1 << endl;
}






}