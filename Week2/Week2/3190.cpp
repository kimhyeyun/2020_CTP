#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };

	//진행 방향
	int cur_dir = 0;
	//방향이 변경되는 시간과 방향이 저장된 index
	int dir_ch_time_idx = 0;

	int N, K, x, y, L, t;
	char d;

	cin >> N >> K;

	vector<vector<int>> board(N, vector<int>(N, 0));
	//변경되는 방향과 시간이 저장된 vector
	vector<pair<int, char> >dir_ch;

	//사과 1, 뱀 -1
	for (int i = 0;i < K;i++) {
		cin >> x >> y;
		board[x-1][y-1] = 1;
	}

	board[0][0] = -1;

	cin >> L;
	for (int i = 0;i < L;i++) {
		cin >> t >> d;
		dir_ch.push_back(make_pair(t, d));
	}

	pair<int, int> head = { 0,0 };
	queue<pair<int, int>> snake;
	snake.push(head);

	int sec = 0;

	while (1) {
		sec++;

		int nx = head.first + dx[cur_dir];
		int ny = head.second + dy[cur_dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			break;
		else if (board[nx][ny] == -1)
			break;
		else if (board[nx][ny] != 1) {
			pair<int,int> tail = snake.front();
			snake.pop();

			board[tail.first][tail.second] = 0;
		}

		head = { nx,ny };
		snake.push(head);

		board[nx][ny] = -1;

		int dir_ch_s = dir_ch[dir_ch_time_idx].first;
		if (dir_ch_time_idx < L && dir_ch_s == sec) {
			char dir = dir_ch[dir_ch_time_idx].second;
			if (dir == 'L') //좌회전
				cur_dir = (cur_dir + 3) % 4;
			if (dir == 'D') //우회전
				cur_dir = (cur_dir + 1) % 4;

			dir_ch_time_idx++;
		}
	}

	cout << sec << "\n";
	return 0;

}