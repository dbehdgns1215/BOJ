#include <bits/stdc++.h>
using namespace std;

int N;

// 팰린드롬 수인지 확인하는 함수 ( O(N) )
bool isPalindrome(int num) {
    string str = to_string(num);
    string rev_str = string(str.rbegin(), str.rend());
    return str == rev_str;
}

// 소수인지 확인하는 함수 ( O(루트N) )
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> N;

    while (true) {
        if (isPalindrome(N) && isPrime(N)) {
            cout << N;
            break;
        }
        N++;
    }
}