#include<iostream>
using namespace std;

int main() {
	cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int test_case = 1;test_case <= T;test_case++) {
		int A, B;
		cin >> A >> B;
		cout << A + B << "\n";
	}
}