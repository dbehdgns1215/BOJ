#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> v;
vector <string> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	// 문자열 입력 받기
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	// VPS인지 검사
	for (int i = 0; i < n; i++)
	{
		bool flag = true;
		ans.clear();
		for (int k = 0; k < v[i].length(); k++)
		{
			if (v[i][k] == '(')
			{
				ans.push_back("(");
			}
			else if (v[i][k] == ')')
			{
				if (!ans.empty() && ans.back() == "(")
				{
					ans.pop_back();
				}
				else if (ans.empty())
				{
					flag = false;
					break;
				}
			}
		}
		if (flag && ans.empty())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

}