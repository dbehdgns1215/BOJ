#include <bits/stdc++.h>
using namespace std;

int main() {
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    int arr[3] = {num1, num2, num3};
    sort(arr, arr + 3);

    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    return 0;
}
