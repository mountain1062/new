#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int visit[10][10];
int temp[10][10];
int main() {
	int a = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			visit[i][j] = a++;
		}
	}
	memcpy(temp, visit, sizeof(visit));
	
	
	cout << "visit" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	
	cout << "temp" << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout<<temp[i][j]<<' ';
		}
		cout << '\n';
	}
}