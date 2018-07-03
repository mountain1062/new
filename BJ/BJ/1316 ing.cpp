#include <iostream>
#include <string>
using namespace std;

int T;
int Grp;


int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		int cnt[26] = { 0 };
		string input;
		cin >> input;
		if (input.length() == 1) continue;
		
		for (int i = 0; i<input.length(); i++) {
			int chk = input.at(i) - 'a';

			if (cnt[chk] != 0 && chk != i - 1) break;
			else cnt[chk]++;

			if (i == input.length() - 1) Grp++;


		}
	}
	cout << Grp;
}