#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

#define MAX 1000001

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str, bomb;
	cin >> str >> bomb;

	char stk[MAX]; //stack대신 배열 이용, stack 인척

	int idx = 0;

	for (int i = 0;i < str.length();i++) {
		stk[idx++] = str[i];

		if (stk[idx - 1] == bomb[bomb.length() - 1]) {
			if (idx < bomb.length())
				continue;
			bool flag = true;
			for (int j = 0;j < bomb.length();j++) {
				if (bomb[bomb.length() - 1 - j] != stk[idx - 1 - j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				idx -= bomb.length();
			}
		}
	}

	if (idx==0)
		cout << "FRULA" << "\n";
	
	for (int i = 0;i < idx;i++)
		cout << stk[i];
	cout << "\n";
}