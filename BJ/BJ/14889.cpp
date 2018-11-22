/*14889번 스타트와 링크*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>v,tt;
int N, Map[20][20], ST[10], LT[10], ST_sum, LT_sum, valance = 1e9, temp[4];
int visit[10];
int a[2];
void go(int n,int s) {
	if (n == 2) {
		//cout << a[0] << ' ' << a[1] << endl;
		ST_sum = ST_sum + Map[temp[0]][temp[1]] + Map[temp[1]][temp[0]];
		LT_sum = LT_sum + Map[temp[2]][temp[3]] + Map[temp[2]][temp[3]];
	}
	else {
		for (int i = s; i < N/2; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				temp[n] = ST[i];
				temp[n + 2] = LT[i];
				a[n] = i;
				go(n + 1,i);
				a[n] = 0;
				temp[n + 2] = 0;
				temp[n] = 0;
				visit[i] = 0;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	int result,a,b;
	for (int r = 0; r < N; r++)	{
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
		}
		v.push_back(r);
	}
	//조합 생성
	do {
		for (int i = 0; i < N; i++) {
			if (i < N / 2) 	ST[i] = v[i];
			else LT[i - N / 2] = v[i];
		}
		ST_sum = LT_sum = 0;
		go(0, 0);
		(ST_sum - LT_sum) > 0 ? (result = ST_sum - LT_sum) : (result = LT_sum - ST_sum);
		
		if (valance > result) {
			valance = result;
			tt = v;
			a = ST_sum;
			b = LT_sum;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << valance << endl;
	for (int i = 0; i < N; i++) cout << tt[i] << ' ';
	cout << endl;
	cout << a << ' '<<b;
}