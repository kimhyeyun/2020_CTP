#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<char> stk;

	string answer;
	string str;
	cin >> str;

	for (int i = 0;i < str.length();i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			answer += str[i];
		}

		switch (str[i]) {
		case '(':
			stk.push(str[i]);
			break;

		case '*':
		case '/':
			while (!stk.empty() && (stk.top() == '*' || stk.top() == '/')) {
				answer += stk.top();
				stk.pop();
			}
			stk.push(str[i]);
			break;

		case '+':
		case '-':
			while (!stk.empty() && stk.top() != '(') {
				answer += stk.top();
				stk.pop();
			}
			stk.push(str[i]);
			break;

		case ')':
			while (!stk.empty() && stk.top() != '(') {
				answer += stk.top();
				stk.pop();
			}
			stk.pop();
			break;
		}
	}

	while (!stk.empty()) {
		answer += stk.top();
		stk.pop();
	}
	cout << answer << "\n";
}