#include <iostream>
#include <queue>
using namespace std;
struct pint { int r, c; }temp;
queue<pint>Q;
int Map[8][8];//0:빈공간, 1:벽, 2:바이러스
int visit[8][8];
int drc[] = { -1,1,0,0,0,0,-1,1 };//상하좌우?
int Max_safeArea;
int M, N;
pint fw, sw, tw;//새울 벽들의 위치 정보 저장

void bfs(int *MapArr[8],int *visitArr[8]) {
	while (!Q.empty()) {
		int rr = Q.front().r;
		int cc = Q.front().c;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + drc[d];
			int nc = cc + drc[d + 4];
			if (!(nr < 0 || nr >= N || nc < 0 || nc >= M) && MapArr[nr][nc] == 0 && visitArr[nr][nc] == 0) {
				MapArr[nr][nc] = 2;
				visitArr[nr][nc] = 1;
			}
		}
	}
}
void setWall(int wallnum) {
	if (wallnum > 3) {
		bfs(Map,visit);
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (Map[i][j] == 0) {
					Map[i][j] = 1;
					setWall(wallnum + 1);
					Map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 2) {
				temp.r = i;
				temp.c = j;
				Q.push(temp);
				visit[i][j] = 1;
			}
		}
	}
	setWall(1);
}