#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    
    

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

     vector<int> w(n);

    for(int i = 0; i < n; i++){
      cin >> w[i];  
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == a[j] && w[i] < w[j]){
                sum += w[i];
            }else{
                sum += w[j];
            }
        }
    }

    cout << sum << endl;
    return 0;




}
