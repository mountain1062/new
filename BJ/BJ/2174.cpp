#include <iostream>
#include <vector>
using namespace std;
struct rbt { int numb; int x, y;	char dir; }temp; // ·Îº¿ ³Ñ¹ö, ÁÂÇ¥, Çö¹æÇâ(0:ºÏ,1:µ¿,2:³²,3:¼­)
//struct comd { char mov; int times; }input;// ÀÌµ¿¸í·É, ¹Ýº¹È½¼ö
vector <rbt>R;

int A, B, N, M;
int Map[101][101];
int outflag;//0: OK 1: Wall 2: Robot
int crash_R;
// ºÏµ¿³²¼­
int dx[] = { -1,0,1,0 }; 
int dy[] = { 0,1,0,-1 };


int run(int s, char c, int t) {
	int Ry = R.at(s - 1).x;
	int Rx = R.at(s - 1).y;
	char Rdir = R.at(s - 1).dir;
	
	if (c == 'F') {
		for (int i = 0; i < t; i++) {
			Map[Rx][Ry] = 0;
			if (Rdir == 'N') {
				Rx = Rx + dx[0];
				Ry = Ry + dy[0];
			}
			else if (Rdir == 'E') {
				Rx = Rx + dx[1];
				Ry = Ry + dy[1];
			}
			else if (Rdir == 'S') {
				Rx = Rx + dx[2];
				Ry = Ry + dy[2];
			}
			else if (Rdir == 'W') {
				Rx = Rx + dx[3];
				Ry = Ry + dy[3];
			}

			if (Rx < 1 || Rx >B || Ry < 1 || Ry >A) {
				return 1;
			}
			else {
				if (Map[Rx][Ry] != 0) {
					crash_R = Map[Rx][Ry];
					return 2;
				}
				else {
					Map[Rx][Ry] = s;
					R.at(s - 1).x = Ry;
					R.at(s - 1).y = Rx;
				}
			}
		}
	}
	else {
		int spin = t % 4;
		for (int i = 0; i < spin; i++) {
			if (c == 'R') {
				if (Rdir == 'N') {
					Rdir = 'W';
					R.at(s - 1).dir = Rdir;
				}
				else if (Rdir == 'E') { 
					Rdir = 'N';
					R.at(s-1).dir = Rdir; 
				}
				else if (Rdir == 'S') {
					Rdir = 'E';
					R.at(s - 1).dir = Rdir;
				}
				else if (Rdir == 'W') {
					Rdir = 'S';
					R.at(s - 1).dir = Rdir;
				}
			}
			else if (c == 'L') {
				if (Rdir == 'N') {
					Rdir = 'E';
					R.at(s - 1).dir = Rdir;
				}
				else if (Rdir == 'E') {
					Rdir = 'S';
					R.at(s - 1).dir = Rdir;
				}
				else if (Rdir == 'S') {
					Rdir = 'W';
					R.at(s - 1).dir = Rdir;
				}
				else if (Rdir == 'W') {
					Rdir = 'N';
					R.at(s - 1).dir = Rdir;
				}
			}
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> temp.x >> temp.y >> temp.dir;
		R.push_back(temp);
		Map[temp.y][temp.x] = i;
	}

	for (int i = 1; i <= M; i++) {
		int select_R, times;
		char comd;
		cin >> select_R >> comd >> times;
		outflag = run(select_R, comd, times);
		if (outflag == 1) {
			cout << "Robot " << select_R << " crashes into the wall" << '\n';
			return 0;
		}
		else if (outflag == 2) {
			cout << "Robot " << select_R << " crashes into robot " << crash_R << '\n';
			return 0;
		}
	}
	
	cout << "OK";
}