#include<iostream>
using namespace std;

char star[2200][2200];

void init() {
	for (int i = 0;i < 2200;i++) {
		for (int j = 0;j < 2200;j++)
			star[i][j] = ' ';
	}
}
void start(int i, int j, int N) {
	if (N == 1) {
		star[i][j]='*';
		return;
	}
	int div = N / 3;
	
	for (int x = 0;x < 3;x++) {
		for (int y = 0;y < 3;y++) {
			if (x == 1 && y == 1)
				;

			else
				start(i + (x * div), j + (y * div), div);
		}
	}
	
	return;
}

int main() {
	int N;

	cin >> N;
	init();
	start(0, 0, N);

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++)
			cout << star[i][j];

		cout << "\n";
	}

	
}