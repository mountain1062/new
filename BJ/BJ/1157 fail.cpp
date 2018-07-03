#include <iostream>
#include <string>
using namespace std;

string input;
int cnt[26];
int temp, chk;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) >= 'a' && input.at(i) <= 'z')
			chk = input.at(i) - 'a';
		else if (input.at(i) >= 'A' && input.at(i) <= 'Z')
			chk = input.at(i) - 'A';

		cnt[chk]++;
	}
	for (int i = 1; i < 26; i++) {
		if (cnt[temp] == cnt[i] && cnt[temp] != 0) {
			cout << '?';
			return 0;
		}
		else if (cnt[temp] < cnt[i]) temp = i;
	}
	char output = 'A' + temp;
	cout << output;
}