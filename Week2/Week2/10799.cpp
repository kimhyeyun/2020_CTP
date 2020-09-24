#include<iostream>
#include<stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int answer = 0;

	stack<char> stk;

	cin >> str;

	for (int i = 0;i < str.length();i++) {
		if (str[i] == '(') 
			stk.push(str[i]);
		else {
			stk.pop();
			if (str[i - 1] == ')') //�ٷ� ���� )��� �̹��� )��ȣ�� �������� ���� �ǹ��ϹǷ� 1�� +
				answer += 1;
			else
				answer += stk.size();
		}
	}

	cout << answer << "\n";
}