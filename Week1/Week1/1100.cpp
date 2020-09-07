#include<iostream>
using namespace std;

int main() {

	char chess[8][8];
	int cnt = 0;
	int j;

	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++)
			cin >> chess[i][j];
	}

	for (int i = 0;i < 8;i++) {
		if (i % 2 == 0)
			j = 0;
		else
			j = 1;

		for (;j < 8;j += 2) {
			if (chess[i][j] == 'F')
				cnt++;
		}

	}

	cout << cnt << "\n";
}