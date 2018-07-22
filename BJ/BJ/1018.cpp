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
			if (Board[i][j] == 'W') { //ÁÂ»ó´Ü Ã³À½ÀÌ W ÀÏ¶§
				for (int m = 0; m < 8; m++) {
					for (int n = 0; n < 8; n++) {
						if (m % 2 == 0) {//Â¦¼ö Çà
							if (n % 2 == 0 && Board[m + i][n + j] != 'W') //Â¦¼ö ¿­ && W ¾Æ´Ò ¶§
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'B') //È¦¼ö ¿­ && B°¡ ¾Æ´Ò ‹š
								cnt++;
						}
						else if (m % 2 == 1) { //È¦¼ö Çà
							if (n % 2 == 0 && Board[m + i][n + j] != 'B') //Â¦¼ö¿­ && B°¡ ¾Æ´Ò ¶§
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'W') //Â¦¼ö¿­ && W°¡ ¾Æ´Ò ‹š
								cnt++;
						}
					}
				}
			}
			else if (Board[i][j] == 'B') { //ÁÂ»ó´Ü Ã³À½ÀÌ B ÀÏ¶§
				for (int m = 0; m < 8; m++) {
					for (int n = 0; n < 8; n++) {
						if (m % 2 == 0) {//Â¦¼ö Çà
							if (n % 2 == 0 && Board[m + i][n + j] != 'B') //Â¦¼ö ¿­ && B°¡ ¾Æ´Ò ¶§
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'W') //È¦¼ö ¿­ && W°¡ ¾Æ´Ò ‹š
								cnt++;
						}
						else if (m % 2 == 1) { //È¦¼ö Çà
							if (n % 2 == 0 && Board[m + i][n + j] != 'W') //Â¦¼ö¿­ && W°¡ ¾Æ´Ò ¶§
								cnt++;
							else if (n % 2 == 1 && Board[m + i][n + j] != 'B') //Â¦¼ö¿­ && B°¡ ¾Æ´Ò ‹š
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