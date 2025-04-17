#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int ans = 0;
    string Yomikomi;


    bool login = false;

    for(int i=0; i<N; i++){
        cin >> Yomikomi;

        if(Yomikomi == "login"){
            login = true;
        }

        if(Yomikomi == "logout"){
            login = false;
        }

        if(Yomikomi == "public"){
            continue;
            string Yomikomi;
        }

        if(Yomikomi == "private" && login == true){
            continue;
            string Yomikomi;
        }else if(Yomikomi == "private" && login == false){
            ans++;
        }
        string Yomikomi;




    }
    cout << ans << endl;







}