#include <iostream>
using namespace std;
int Map[50][50]; // ��:1 û��X:0 û��o:2
int N, M;//���� , ����
int r, c, d;//r,c : ��ǥ , d : ���� (0:�� 1:�� 2:�� 3:��)
int clean;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	cin >> r >> c >> d;

	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> Map[n][m];

		}
	}

	Map[r][c] = 2;
	clean++;

	while (1) {

		if ((Map[r - 1][c] != 0) && (Map[r + 1][c] != 0) && (Map[r][c - 1] != 0) && (Map[r][c + 1] != 0)) {//�������� �� û�҉�ų� ���� ��
			if (d == 0) {
				if (Map[r + 1][c] == 1) break;
				else r = r + 1;
			}
			else if (d == 1) {
				if (Map[r][c - 1] == 1)break;
				else c = c - 1;
			}
			else if (d == 2) {
				if (Map[r - 1][c] == 1)break;
				else r = r - 1;
			}
			else if (d == 3) {
				if (Map[r][c + 1] == 1)break;
				else c = c + 1;
			}

		}
		else {
			if (d == 0) {
				if (Map[r][c - 1] == 0) { // ������ û�Ұ� �ȵ� ����
					d = 3;
					Map[r][c - 1] = 2;
					clean++;
					c = c - 1;
				}
				else d = 3;
			}
			else if (d == 1) {
				if (Map[r - 1][c] == 0) {
					d = 0;
					Map[r - 1][c] = 2;
					clean++;
					r = r - 1;
				}
				else d = 0;
			}
			else if (d == 2) {
				if (Map[r][c + 1] == 0) {
					d = 1;
					Map[r][c + 1] = 2;
					clean++;
					c = c + 1;
				}
				else d = 1;
			}
			else if (d == 3) {
				if (Map[r + 1][c] == 0) {
					d = 2;
					Map[r + 1][c] = 2;
					clean++;
					r = r + 1;
				}
				else d = 2;
			}
		}

	}
	cout << clean;

}