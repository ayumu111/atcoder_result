#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitString(const string & s, int w) {
    vector<string> result;
    for (size_t i = 0; i < s.size(); i += w) {
        result.push_back(s.substr(i, w));
    }
    return result;
}

int main() {
    string S;
    int w;

    
    cin >> S;
    
    cin >> w;
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < w; j++){
            if(S[i] == ' '){
                cout << " ";
            }
            else{
                cout << S[i];
            }
        }

       vector<string> segments = splitString(S, w);
        
    
    
    }
    cout << "The string split into " << w << "-character segments:" << endl;
   

    return 0;
}
