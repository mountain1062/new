#include<cstdio>
int N, M, a[9];
void go(int cur, int idx) {
	if (cur == M) {
		for (int i = 0; i < cur; i++) printf("%d ", a[i]);
		puts("");
	}
	for (int i = idx + 1; i <= N; i++) {
		a[cur] = i;
		go(cur + 1, i);
	}
}
int main() {
	scanf("%d%d", &N, &M);
	go(0, 0);
}