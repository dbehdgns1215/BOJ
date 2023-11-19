#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	string s;

	// cin >> s; cin는 첫 번째 공백 이전까지의 문자열만을 읽어들임
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			cnt++; // 공백 이전 문자의 개수를 세는 형식.
		}
	}

	if (s[s.length()-1] != ' ') // 공백으로 끝나지 않는 문장은
	{							// 추가로 1을 더 더해줘야 함.
		cnt++;					// The Curious Case of Benjamin Button
	}							// (1 )(   2  )( 3 )(4)(   5   )(  6  ) 이어야 되는데
								         // Button 뒤에는 공백이 없어서 카운트가 안됨.
	if (s[0] == ' ') // 반대로 처음에 공백이 들어오면
	{				 // 무조건 1개의 단어가 더 있는 것으로 나오기에 카운트에서 제외시켜줌.
		cnt--;
	}

	cout << cnt;  // (a )(b )(c ) -> 공백으로 끝나는 문자는 공백 이전 문자를 개수로 세니
				  // 정삭적으로 카운트 됨.
}