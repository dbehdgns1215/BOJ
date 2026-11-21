#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string hex;
    cin >> hex;

    int dec = 0;
    int len = hex.length();
    
    for(int i=0; i<len; i++) {
        int temp;
        if('0'<=hex[i] && hex[i]<='9') {
            temp = hex[i] - '0';
        } else {
            temp = hex[i] - 'A' + 10;
        }
        dec = dec*16 + temp;
    }

    cout << dec;
}
