#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int visit[3] = { 0,1,0 };
int arr[3];
int temp[10][10];
int main() {
	for (int i = 0; i < 3 && visit[i] == 0; i++) {
		arr[i] = 1;
	}
	for (int i = 0; i < 3; i++) {
		cout <<i<<"¹ø : "<< arr[i] << endl;
	}
}