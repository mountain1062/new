#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	long long A, B, out;
	cin >> A >> B;
	out = (A + B)*(A - B);
	cout << out;
}