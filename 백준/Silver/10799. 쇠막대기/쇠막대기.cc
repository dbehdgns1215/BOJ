#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string line;
	int pipe = 0;

	getline(cin, line);

	stack<char> stk;


	for (int i = 0; i < line.size(); i++)
	{	
		if (line[i] == '(')
		{
			stk.push(line[i]);
		}
		else if (!stk.empty() && line[i] == ')')
		{
			if (stk.top() == '(')
			{
				stk.pop();

				if (line[i - 1] == '(')
				{
					pipe = pipe + stk.size();
				}
				else {
					pipe++;
				}
			}
		}
	}
	cout << pipe;
}