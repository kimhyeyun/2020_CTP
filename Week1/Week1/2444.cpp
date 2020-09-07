#include<iostream>
using namespace std;

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = i;j < N - 1;j++)
			cout << " ";
		for(int k=0;k<2*(i+1)-1;k++)
			cout << "*";
		cout << "\n";
	}
	for (int i = 1;i < N;i++) {
		for (int j = 0;j < i;j++)
			cout << " ";
		for (int k = 0;k < 2 * (N - i) - 1;k++)
			cout << "*";
		cout << "\n";
	}


}