#include <iostream>
#include <string>
using namespace std;
int T,r;
string input;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> r >> input;
		for (int i = 0; i < input.length(); i++) {
			for (int j = 0; j < r; j++) {
				cout << input[i];
			}
		}
		cout << '\n';
	}
}