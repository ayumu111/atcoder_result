#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll T;
    cin >> n >> T;

    string s;
    cin >> s;

    vector<ll> x0, x1;

   for(int i = 0; i < n; i++){
    ll x;
    cin >> x;  
    if(s[i] == '0'){
        x0.push_back(x);
    }else{
        x1.push_back(x);
    }

   }

   sort(x1.begin(), x1.end());
   sort(x0.begin(), x0.end());

   int l = 0;
   int r = 0;
   ll sum = 0;

   for(int i = 0; i < (int)x1.size(); ++i){
    
         while(l < (int)x0.size() && x1[i] > x0[l])l++;
         while(r < (int)x0.size() && x1[i] + (2 * T) >= x0[r])r++; 
      sum += r-l;
   }

    cout << sum << endl;
     return 0;



   












}