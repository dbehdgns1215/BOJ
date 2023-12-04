#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int cent;
        cin >> cent;

        int qCount = cent / 25;
        cent %= 25;

        int dCount = cent / 10;
        cent %= 10;

        int nCount = cent / 5;
        cent %= 5;

        int pCount = cent;

        cout << qCount << " " << dCount << " " << nCount << " " << pCount << "\n";
    }

}
