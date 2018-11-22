#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <time.h>
using namespace std;
int visit[10][10];
int temp[10][10];
char a[2][2];
string b[2];
int Arr[20];
int comb[10][10];
vector<int>v;
int bbq_size = 10;
int M = 1;
clock_t s, e;
int cnt;
void combi(int n, int k) {
	do {
		for (int i = 0; i < v.size(); i++) {
			//cout << v[i] << ' ';
		}
		cnt++;
	} while (next_permutation(v.begin(), v.end()));
}

int main() {

	for (int i = 0; i < M; i++) v.push_back(1);
	for (int i = 0; i < bbq_size - M; i++) v.push_back(0);
	sort(v.begin(),v.end());

	combi(bbq_size, M);
	cout << cnt << endl;
	cout << double(e - s);

}