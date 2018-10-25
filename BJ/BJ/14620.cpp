/*14620�� �ɱ�*/
#include <iostream>
using namespace std;
int N;
int Map[10][10];
int visit[10][10];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int Min_cost = 1e9;

//dfs Ž�� ���� : 0 < r,c < N-1 �� �����¿� Ž�� �� �� ���� �ʰ� üũ�� ���ص� ��//
int Add_flower(int r, int c) {
	if (visit[r][c] != 0) return 0; //����ġ�� ������� ������ Ż��
	else {
		int able[4] = { 0 };
		//�����¿찡 �� ������� üũ
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (visit[nr][nc] == 0) {
				able[d] = 1;
			}
		}
		//�����¿찡 �� ������� ���� �ɴ´�.
		if (able[0] == 1 && able[1] == 1 && able[2] == 1 && able[3] == 1) {
			visit[r][c] = 1;
			for (int d = 0; d < 4; d++) {
				int nr = r + drc[d];
				int nc = c + drc[d + 4];
				visit[nr][nc] = 1;
			}
			return 1;
		}
		//�ƴϸ� �׳� Ż��
		else return 0;
	}
}
void Remove_flower(int r, int c, int flag) {
	if (flag == 1) {
		visit[r][c] = 0;
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			visit[nr][nc] = 0;
		}
	}
	else return;
}
void dfs(int flower_cnt) {
	if (flower_cnt > 3) { // �� 3�� �� �ɾ��� ��
		int min_temp = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (visit[r][c] == 1) {
					min_temp = min_temp + Map[r][c];
				}
			}
		}
		if (Min_cost >= min_temp) {
			Min_cost = min_temp;
		}
		return;
	}
	else {
		for (int rr = 1; rr < N - 1; rr++) {
			for (int cc = 1; cc < N - 1; cc++) {
				int Add_flag = Add_flower(rr, cc);
				if (Add_flag == 1) {
					dfs(flower_cnt + 1);
					Remove_flower(rr, cc, Add_flag);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
		}
	}
	
	dfs(1);

	cout << Min_cost;
}