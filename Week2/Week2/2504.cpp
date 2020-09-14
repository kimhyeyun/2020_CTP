#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> stk;
	string s;
	cin >> s;

	long long result = 0;
	int tmp = 1;
	bool flag = false;

	for (int i = 0;i < s.length();i++) {
		if (s[i] == '(') {
			tmp *= 2;
			stk.push('(');
		}
		else if (s[i] == '[') {
			tmp *= 3;
			stk.push('[');
		}
		
		//불가능한 경우
		else if (s[i] == ')' && (stk.empty() || stk.top()!='(')) {
			flag = true;
			break;
		}

		else if (s[i] == ']' && (stk.empty() || stk.top() != '[')) {
			flag = true;
			break;
		}
		
		else if (s[i] == ')') {
			if (s[i - 1] == '(')
				result += tmp;
			stk.pop();
			tmp /= 2;
		}

		else if (s[i] == ']') {
			if (s[i - 1] == '[')
				result += tmp;
			stk.pop();
			tmp /= 3;
		}
	}

	if (flag || !stk.empty())
		cout << 0 << "\n";
	else
		cout << result << "\n";
	return 0;
}