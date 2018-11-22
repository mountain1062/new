/*15686번 치킨배달*/
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
struct pnt { int r, c; }house[100], bbq[13];
queue<int>min_Q;
vector<int>combv;
int N, M, Map[50][50];
int house_cnt, bbq_cnt, Min_dis = 1e9;

void cal_min(vector<pnt>alive) {
	int min_temp, temp_dis = 0;
	for (int h = 0; h < house_cnt; h++) {
		min_temp = abs(house[h].r - alive[0].r) + abs(house[h].c - alive[0].c);
		for (int j = 1; j < M; j++) {
			if (min_temp > abs(house[h].r - alive[j].r) + abs(house[h].c - alive[j].c)) {
				min_temp = abs(house[h].r - alive[j].r) + abs(house[h].c - alive[j].c);
			}
		}
		min_Q.push(min_temp);
	}
	while (!min_Q.empty()) {
		temp_dis += min_Q.front();
		min_Q.pop();
	}
	if (Min_dis > temp_dis) {
		Min_dis = temp_dis;
	}
	
}

void comb(int n, int k) {
	
	do {
		vector<pnt>alive;
		for (int i = 0; i < combv.size(); i++) {
			if (combv[i] == 1) {
				alive.push_back(bbq[i]);
			}
		}
		cal_min(alive);
	} while (next_permutation(combv.begin(), combv.end()));
	
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Map[r][c];
			if (Map[r][c] == 1) {
				house[house_cnt].r = r;
				house[house_cnt].c = c;
				house_cnt++;
			}
			if (Map[r][c] == 2) {
				bbq[bbq_cnt].r = r;
				bbq[bbq_cnt].c = c;
				bbq_cnt++;
			}
		}
	}
	for (int i = 0; i < bbq_cnt - M; i++)combv.push_back(0);
	for (int i = 0; i < M; i++) combv.push_back(1);
	
	comb(bbq_cnt, M);
	cout << Min_dis;
}


//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <time.h>
//#define INF 100000000
//
//using namespace std;
//clock_t s, e;
//class COORD {            //좌표 저장하기 위한 클래스
//public:
//	int x, y;
//	COORD(int y, int x) {
//		this->x = x;
//		this->y = y;
//	}
//};
//
//int rst = INF, n, m;
//vector<COORD> house, chicken;
//
//int select(int arr[]) {     //구해진 조합을 가지고 집과의 거리를 비교하고 도시의 치킨 거리를 구해주는 함수
//	int sum = 0;
//	for (int i = 0; i < house.size(); i++) {
//		int distance = INF;
//		for (int j = 0; j < m; j++) {
//			int temp = abs(house[i].x - chicken[arr[j]].x) + abs(house[i].y - chicken[arr[j]].y);
//			distance = (temp < distance) ? temp : distance;
//		}
//		sum += distance;
//	}
//	return sum;
//}
//
//void combination(int arr[], int index, int n, int k, int target) {          //치킨집의 모든 조합 구해주는 함수(조합)
//	if (k == 0) {
//		int temp = select(arr);
//		rst = (temp < rst) ? temp : rst;           //새로 구해진 치킨거리가 더 적으면 결과값을 바꿔준다
//	}
//	else if (target == n)
//		return;
//	else {
//		arr[index] = target;
//		combination(arr, index + 1, n, k - 1, target + 1);
//		combination(arr, index, n, k, target + 1);
//	}
//}
//
//int main() {
//
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			int temp;
//			scanf("%d", &temp);
//			if (temp == 2)
//				chicken.push_back(COORD(i, j));
//			if (temp == 1)
//				house.push_back(COORD(i, j));
//		}
//	}
//	int *arr = new int[m];
//	s = clock();
//	combination(arr, 0, chicken.size(), m, 0);
//	e = clock();
//	cout << double(e - s) << endl;
//	printf("%d", rst);
//
//	return 0;
//}
