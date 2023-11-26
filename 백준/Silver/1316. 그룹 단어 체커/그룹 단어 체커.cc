#include <bits/stdc++.h>
using namespace std;


	// 그룹 단어의 메커니즘

	// 처음 나온 문자들만 존재 -> 그룹 단어
	// 2개 이상 나온 문자들이 있고 문자들이 이어져 있음 -> 그룹 단어
	
	// 2개 이상 나온 문자들이 있고 문자들이 하나라도 떨어져 있음 -> 그룹 단어가 아님

	// 첫 번째 단어부터 순차적으로 확인을 하는 것을 기본 원칙으로 삼는다.
	
	// 일단 기본적으로 **이전에 나왔던 단어가 재등장 할 때** 를 어떻게 컨트롤 하느냐가 문제 해결의 키포인트.
	
	// 예를 들어 aaabbccca 라는 단어를 보면 aaa bb ccc 로 그룹단어를 잘 유지하다가 마지막 a가 그룹 단어를 망치게 된 상황.
	// 이를 코드로 구현하려면 bool형의 check 배열을 만들고 처음 나오는 단어를 true로 바꿔주면 된다.
	
	// check 배열이 이미 true인 경우는 **이전에 나왔었다** 는 말인데
	
	// 첫 번째부터 끝까지 순차적 (-> 방향)으로 확인하고 있기 때문에
	// 바로 이전 idx의 단어와 붙어있냐만 확인하면 된다. (단방향)
	
	// 이미 나온 단어인데 바로 전 idx와 같은 단어라면 -> 그룹 단어
	// 이미 나온 단어인데 바로 전 idx와 다른 단어라면 -> 그룹 단어 X

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	int t, cnt = 0;
	
	
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		bool check[26] = { false };
		bool group = true;

		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			// 처음 나온 문자인지 확인
			if (check[(int)str[i] - 97] == false) {
				check[(int)str[i] - 97] = true;
			}
			
			// 이전에 나왔던 문자. 이어지는지 아닌지 확인해야함.
			else if (check[(int)str[i] - 97] = true)
			{
				if (str[i] != str[i - 1])
				{
					group = false; // 이전에 나왔는데 이전 문자와 다르다면 그룹 단어 X
					break;
				}
			}
		}
		if (group == true)
		{
			cnt++;
		}
	}

	cout << cnt;
}