#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int clubs[100010] = {};
    int menber[100010] = {};
    int user[100010] = {};


for(int i = 0; i < clubs.size(); i++){
    for(int j = 0 j < menber.size(); j++){
        for(int k = 0; k < user.size(); k++){
        if(clubs[i].members[k] == user[j]){
            cout<<"user["<<j<<"] is in club ["<<i<<"]"endl;
        }
    }
   }
}










}
