#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	stack<double> stk;

	int N;
	cin >> N;

	string str;
	cin >> str;

	vector<double> operand;

	double x, y;

	for (int i = 0;i < N;i++) {
		double a;
		cin >> a;
		operand.push_back(a);
	}

	for (int i = 0;i < str.length();i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			stk.push(operand[str[i] - 65]);
		}

		switch(str[i]) {
		case '+':
			x = stk.top();
			stk.pop();
			y = stk.top();
			stk.pop();
			stk.push(x + y);
			break;

		case '-':
			x = stk.top();
			stk.pop();
			y = stk.top();
			stk.pop();
			stk.push(y-x);
			break;

		case '*':
			x = stk.top();
			stk.pop();
			y = stk.top();
			stk.pop();
			stk.push(x * y);
			break;

		case '/':
			x = stk.top();
			stk.pop();
			y = stk.top();
			stk.pop();
			stk.push(y / x);
			break;
		}
	}

	printf("%.2f\n", stk.top());


}