#include <iostream>
#include <vector>
#include<queue>
using namespace std;
struct T
{
	int a;
	string b;
	char c;
}temp;
queue<int>Q;
vector <T> v;
int main() {
	string A[2];
	A[0] = "abcde";
	A[1] = "12345";
	cout << A[0][0] << '\n';
	cout << A[0][5] << '\n';

	cout << A[1][0] << '\n';
	cout << A[1][4] << '\n';
}