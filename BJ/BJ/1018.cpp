#include <iostream>
using namespace std;
char Board[51][51];
int R, C;
int cnt, min_cnt;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for (int m = 0; m < R; m++) {
		for (int n = 0; n < C; n++) {
			cin >> Board[m][n];
		}
	}

	for (int i = 0; i <= R - 8; i++) {
		for (int j = 0; j <= C - 8; j++) {
			cnt = 0;
			if (Board[i][j] == 'W') { //�»�� ó���� W �϶�
				for (int m = 0; m < 8; m++) {
					for (int n = 0; n < 8; n++) {
						if (m % 2 == 0) {//¦�� ��
							if (n % 2 == 0 && Board[m + i][n + j] != 'W') //¦�� �� && W �ƴ� ��
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'B') //Ȧ�� �� && B�� �ƴ� ��
								cnt++;
						}
						else if (m % 2 == 1) { //Ȧ�� ��
							if (n % 2 == 0 && Board[m + i][n + j] != 'B') //¦���� && B�� �ƴ� ��
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'W') //¦���� && W�� �ƴ� ��
								cnt++;
						}
					}
				}
			}
			else if (Board[i][j] == 'B') { //�»�� ó���� B �϶�
				for (int m = 0; m < 8; m++) {
					for (int n = 0; n < 8; n++) {
						if (m % 2 == 0) {//¦�� ��
							if (n % 2 == 0 && Board[m + i][n + j] != 'B') //¦�� �� && B�� �ƴ� ��
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'W') //Ȧ�� �� && W�� �ƴ� ��
								cnt++;
						}
						else if (m % 2 == 1) { //Ȧ�� ��
							if (n % 2 == 0 && Board[m + i][n + j] != 'W') //¦���� && W�� �ƴ� ��
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'B') //¦���� && B�� �ƴ� ��
								cnt++;
						}
					}
				}
			}
			if (i == 0 && j == 0) min_cnt = cnt;
			else {
				if (cnt <= min_cnt) min_cnt = cnt;
			}
		}
	}
	cout << min_cnt;
}