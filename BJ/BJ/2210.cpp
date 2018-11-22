/*2210번 숫자판 점프*/
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
#include <vector>
using namespace std;
char Map[5][5];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
vector<int>v;
//int MakedNum[15625];
string temp;


void make_num(int c) {
	if (c > 6) {
		v.push_back(atoi(temp.c_str()));
		return;
	}
	else {
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				for (int d = 0; d < 4; d++) {
					int nr = r + drc[d];
					int nc = c + drc[d + 4];
					if (!(nr < 0 || nr >= 5 || nc < 0 || nc >= 5)) {
						temp += Map[nr][nc];
						make_num(c + 1);
						temp.replace(temp.size() - 1, 1, "");
					}
				}
			}
		}
		
	}
}


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int r = 0; r < 5; r++) {
		for (int c = 0; c < 5; c++) {
			cin >> Map[r][c];
		}
	}
	make_num(1);
	sort(v.begin(), v.end());
	stack<int>S;
	S.push(v.at(0));
	for (int i = 1; i < v.size(); i++) {
		if (v.at(i) != S.top()) {
			S.push(v.at(i));
		}
	}
	cout << S.size() << endl;
	return 0;
}
