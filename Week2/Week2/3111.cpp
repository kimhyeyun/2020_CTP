#include<iostream>
#include<string>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<char> dq_front;
	deque<char> dq_back;

	string A, T;
	cin >> A >> T;

	int f_idx = 0, b_idx = T.size() - 1;

	while (f_idx <= b_idx) {
		while (f_idx <= b_idx) {
			bool flag = false;
			dq_front.push_back(T[f_idx++]);
			if (dq_front.size() >= A.size()) {
				flag = true;
				for (int i = 0;i < A.size();i++) {
					if (A[i] != dq_front[dq_front.size() - A.size() + i]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = 0;i < A.size();i++)
					dq_front.pop_back();
				break;
			}
		}

		while (f_idx <= b_idx) {
			bool flag = false;
			dq_back.push_front(T[b_idx--]);
			if (dq_back.size() >= A.size()) {
				flag = true;
				for (int i = 0;i < A.size();i++) {
					if (A[i] != dq_back[i]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				for (int i = 0;i < A.size();i++)
					dq_back.pop_front();
				break;
			}
		}
	}

	string anw;

	for (int i = 0;i < dq_front.size();i++) {
		anw.push_back(dq_front[i]);
	}
	for (int i = 0;i < dq_back.size();i++) {
		anw.push_back(dq_back[i]);
	}

	while (anw.find(A) < 30000)
		anw.erase(anw.find(A), A.size());

	cout << anw << "\n";

}