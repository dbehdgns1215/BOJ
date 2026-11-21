#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        a %= 10;
        
        if(a == 0) {
            cout << 10 << '\n';
            continue;
        }
        
        int arr[10] = {0}, idx = 0;
        int temp = a;
        while(true) {
            arr[idx++] = temp;
            temp = (temp * a) % 10;
            if(temp == a) break;
        }
        
        if(b % idx == 0) cout << arr[idx-1] << '\n';
        else cout << arr[b%idx-1] << '\n';
    }
}
