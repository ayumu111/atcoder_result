#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main(){
int h,w;
cin >> h >> w;
int Q;
cin >> Q;
vector<int> q(Q);
vector<vector<int>> a(h, vector<int>(w));
vector<vector<int>> b(Q, vector<int>());

for(int i = 0; i < Q; i++){
    cin >> q[i];
    if(q[i] == 1){
        int r,c;
        cin >> r >> c;
        a[r-1][c-1] = 1;
    }else{
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        b[i].push_back(x1-1);
        b[i].push_back(y1-1);
        b[i].push_back(x2-1);
        b[i].push_back(y2-1);
    }
}
}
